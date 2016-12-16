/*
This file is part of kynnaugh-cc.

Kynnaugh-cc is free software: you can redistribute it and/or modify
it under the terms of the Apache License, version 2.0 as published by
the Apache Software Foundation, either version 2 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
Apache License, version 2.0 for more details.

You should have received a copy of the Apache License, version 2.0
along with kynnaugh-cc.  If not, see <https://www.apache.org/licenses/LICENSE-2.0>.
*/

#include "speechrec.h"

using namespace ::grpc;
using namespace ::google::cloud::speech::v1beta1;

speechrec::speechrec()
{

}

QString speechrec::recognize(char *buf, size_t length)
{
    std::cerr << "Recognize buffer is of length " << length << std::endl;
    std::unique_ptr<google::cloud::speech::v1beta1::Speech::Stub> stub(Speech::NewStub(CreateChannel("speech.googleapis.com:443", GoogleDefaultCredentials())));
    ::grpc::ClientContext ctx;
    RecognitionConfig *conf = new RecognitionConfig();
    RecognitionAudio *audio = new RecognitionAudio();
    SyncRecognizeRequest req;
    SyncRecognizeResponse res;

    //Set up configuration parameters
    conf->set_profanity_filter(false);
    conf->set_encoding(RecognitionConfig_AudioEncoding_FLAC);
    //conf->set_sample_rate(16000);                             //TODO: Consider making dynamic or just passing in the source sample rate (48 kHz by default)
    conf->set_sample_rate(48000);                             //TODO: Consider making dynamic or just passing in the source sample rate (48 kHz by default)
    conf->set_language_code("en-US");                         //TODO: Recognize another language
    conf->set_max_alternatives(1);

    audio->set_content(buf, length);

    //IMPORTANT: The SyncRecognizeRequest calls free() on conf and audio in its destructor
    //Therefore we have to allocate them but NOT free them
    req.set_allocated_config(conf);
    req.set_allocated_audio(audio);

    Status rw = stub->SyncRecognize(&ctx, req, &res);
    QString retval = "0BLANK0";
    if(rw.ok())
    {
        if(res.results().size() > 0)
        {
            qDebug() << "KYNNAUGH PLUGIN: Got" << res.results().size() << "results!";
            auto result = res.results(0);
            if(result.alternatives().size() > 0)
            {
                qDebug() << "KYNNAUGH PLUGIN: Got" << result.alternatives().size() << "alternatives!";
                auto alternative = result.alternatives(0);
                qDebug() << "KYNNAUGH PLUGIN: Got alternative 0!";
                std::string transcript = alternative.transcript();
                qDebug() << "Got transcript";
                qDebug() << "transcript=" << transcript.c_str();
                retval = QString::fromStdString(transcript);
                qDebug() << "retval=" << retval;
            }
            else
            {
                qDebug() << "KYNNAUGH PLUGIN: res.results(0).alternatives.size() == 0!";
            }
        }
        else
        {
            qDebug() << "KYNNAUGH PLUGIN: res.results.size() == 0!";
        }
    }
    else
    {
        retval = "KYNNAUGH PLUGIN ERROR: Can't transcribe audio due to technical issues.";
        qDebug() << "KYNNAUGH PLUGIN: SyncRecognizeRequest RecognitionAudio error: code="
                  << rw.error_code() << "message=" << rw.error_message().c_str();
    }

    return retval;
}
