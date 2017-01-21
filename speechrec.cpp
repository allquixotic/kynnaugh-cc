/*
This file is part of kynnaugh-cc.

Kynnaugh-cc is free software: you can redistribute it and/or modify
it under the terms of the Apache License, version 2.0 as published by
the Apache Software Foundation, either version 2 of the License, or
(at your option) any later version.

Kynnaugh-cc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
Apache License, version 2.0 for more details.

You should have received a copy of the Apache License, version 2.0
along with kynnaugh-cc.  If not, see <https://www.apache.org/licenses/LICENSE-2.0>.
*/

#include "speechrec.h"
#include "dbg.h"
#include "constants.h"
#include "settings.h"
using namespace ::grpc;
using namespace ::google::cloud::speech::v1beta1;
using namespace std;

speechrec::speechrec()
{

}

QString speechrec::recognize(char *buf, size_t length)
{
    dbg::qStdOut() << "Recognize buffer is of length " << length << "\n";
    ::grpc::ClientContext *ctx = new ::grpc::ClientContext();
    shared_ptr<ChannelCredentials> creds = GoogleDefaultCredentials();
    shared_ptr<Channel> channel = CreateChannel("speech.googleapis.com", creds);
    grpc_connectivity_state connstate = channel->GetState(true);
    if(connstate == GRPC_CHANNEL_SHUTDOWN)
    {
        dbg::qStdOut() << "It says GRPC_CHANNEL_SHUTDOWN\n";
    }
    else if(connstate == GRPC_CHANNEL_READY)
    {
        dbg::qStdOut() << "It says GRPC_CHANNEL_READY\n";
    }
    else
    {
        dbg::qStdOut() << "It's " << connstate << " connection state\n";
    }
    unique_ptr<google::cloud::speech::v1beta1::Speech::Stub> stub(Speech::NewStub(channel));
    RecognitionConfig *conf = new RecognitionConfig();
    RecognitionAudio  *audio = new RecognitionAudio();
    SyncRecognizeRequest *req = new SyncRecognizeRequest();
    SyncRecognizeResponse res;
    SpeechContext *ctxt = new SpeechContext();
    auto settings = settings::getSettings();
    QStringList hints = settings->value(HINTS_SETTING).toStringList();

    if(hints.size() > 0)
    {
        int i = 0;
        foreach(const QString &hint, hints)
        {
            char *prnt = strdup(qPrintable(hint));
            if(prnt != nullptr)
            {
                ctxt->add_phrases(prnt);
            }
        }

        dbg::qStdOut() << "Done building phrases\n";

        conf->set_allocated_speech_context(ctxt);
    }

    //Set up configuration parameters
    conf->set_profanity_filter(false);
    conf->set_encoding(RecognitionConfig_AudioEncoding_FLAC);
    conf->set_sample_rate(16000);                             //TODO: Consider making dynamic or just passing in the source sample rate (48 kHz by default)
    conf->set_language_code("en-US");                         //TODO: Recognize another language
    conf->set_max_alternatives(1);

    std::string *sbuf = new std::string(buf, length);
    audio->set_allocated_content(sbuf);

    //IMPORTANT: The SyncRecognizeRequest calls free() on conf and audio in its destructor
    //Therefore we have to allocate them but NOT free them
    req->set_allocated_config(conf);
    req->set_allocated_audio(audio);

    Status rw = stub->SyncRecognize(ctx, *req, &res);
    QString retval = "0BLANK0";
    if(rw.ok())
    {
        if(res.results().size() > 0)
        {
            dbg::qStdOut() << "KYNNAUGH PLUGIN: Got " << res.results().size() << " results!\n";
            const SpeechRecognitionResult &rezult = res.results(0);
            if(rezult.alternatives_size() > 0)
            {
                dbg::qStdOut() << "KYNNAUGH PLUGIN: Got " << rezult.alternatives().size() << " alternatives!\n";
                auto alternative = rezult.alternatives(0);
                dbg::qStdOut() << "KYNNAUGH PLUGIN: Got alternative 0!\n";
                std::string transcript = alternative.transcript();
                QString confid = QString::number((alternative.confidence() * 100.0), 'f', 2);
                dbg::qStdOut() << "Got transcript = " << transcript.c_str() << "\n";
                retval = QString::fromStdString(transcript);

                if(settings->value(CONFIDENCE_FLAG, true).toBool())
                {
                    retval += " | Confidence: " + confid + "%";
                }
                dbg::qStdOut() << "retval=" << retval << "\n";
            }
            else
            {
                dbg::qStdOut() << "KYNNAUGH PLUGIN: res.results(0).alternatives.size() == 0!\n";
            }
        }
        else
        {
            dbg::qStdOut() << "KYNNAUGH PLUGIN: res.results.size() == 0!\n";
        }
    }
    else
    {
        retval = "KYNNAUGH PLUGIN ERROR: Can't transcribe audio due to technical issues.";
        dbg::qStdOut() << "KYNNAUGH PLUGIN: SyncRecognizeRequest RecognitionAudio error: code="
                  << rw.error_code() << " message=" << rw.error_message().c_str() << "\n";
    }

    delete req;

    return retval;
}
