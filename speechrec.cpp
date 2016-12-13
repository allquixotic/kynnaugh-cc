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
    : stub(Speech::NewStub(CreateChannel("speech.googleapis.com:443", GoogleDefaultCredentials()))), ctx(), configSubmitted(false)
{

}

QString speechrec::recognize(char *buf, size_t length)
{
    setupConfig();
    SyncRecognizeRequest req;
    SyncRecognizeResponse res;
    RecognitionAudio *audio = new RecognitionAudio();
    audio->set_content(buf, length);
    req.set_allocated_audio(audio);
    Status rw = stub->SyncRecognize(&ctx, req, &res);
    QString retval;
    if(rw.ok())
    {
        auto result = res.results(0);
        auto alternative = result.alternatives(0);
        std::string transcript = alternative.transcript();
        retval = QString::fromStdString(transcript);
    }
    else
    {
        retval = "KYNNAUGH PLUGIN ERROR: Can't transcribe audio due to technical issues.";
        std::cerr << "KYNNAUGH PLUGIN: SyncRecognizeRequest RecognitionAudio error: code="
                  << rw.error_code() << "message=" << rw.error_message().c_str()
                  << std::endl;
    }

    return retval;
}

bool speechrec::setupConfig()
{
    if(!configSubmitted)
    {
        RecognitionConfig *conf = new RecognitionConfig();
        SyncRecognizeRequest req;
        SyncRecognizeResponse res;

        //Set up configuration parameters
        conf->set_profanity_filter(false);
        conf->set_encoding(RecognitionConfig_AudioEncoding_FLAC);
        conf->set_sample_rate(16000);                             //TODO: Consider making dynamic or just passing in the source sample rate (48 kHz by default)
        conf->set_language_code("en-US");                         //TODO: Recognize another language
        conf->set_max_alternatives(1);

        req.set_allocated_config(conf);
        Status rw = stub->SyncRecognize(&ctx, req, &res);
        if(!rw.ok())
        {
            std::cerr << "KYNNAUGH PLUGIN: bug or google server down:" << std::endl;
            std::vector<::grpc::string> errors;
            req.FindInitializationErrors(&errors);
            for(::grpc::string error : errors)
            {
                std::cerr << "\t" << error.c_str() << std::endl;
            }
            return false;
        }
        configSubmitted = true;
    }
    return true;
}
