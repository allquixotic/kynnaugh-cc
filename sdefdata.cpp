#include "sdefdata.h"
#include "dbg.h"
#include "ts3_functions.h"
#include "kynnaugh.h"
#include "constants.h"
#include "settings.h"

sdefdata::sdefdata(QByteArray *b, qint32 chan, quint64 sch, anyID cli) :
    QObject(nullptr), byt(b), channels(chan), schid(sch), clientID(cli), buf(b, nullptr)
{}

void sdefdata::start()
{
    convert conv;
    QBuffer *flac = conv.convertRawToFlac(&this->buf, this->channels);
    if(flac->size() == 0)
    {
        dbg::qStdOut() << "No FLAC samples returned, yet number of samples was greater than 0!\n";
    }
    else
    {
        dbg::qStdOut() << "FLAC contains " << flac->size() << " bytes\n";
        QByteArray qba = flac->data();
        QString chatline = sampledef::rec.recognize(qba.data(), flac->size());
        dbg::qStdOut() << "Returned from rec.recognize()!\n";
        if(chatline != QString("0BLANK0"))
        {
            char *nickname = nullptr;
            struct TS3Functions *ff = ts3func::funcs;
            ff->getClientVariableAsString(this->schid, this->clientID, ClientProperties::CLIENT_NICKNAME, &nickname);
            if(nickname != nullptr && qstrlen(nickname) > 0)
            {
                chatline = QString("Speech Recognition! [") + QString(nickname) + QString("]: ") + chatline;
            }
            else
            {
                chatline = QString("Speech Recognition! [UNKNOWN USER]: ") + chatline;
            }

            const std::string stidstring = chatline.toStdString();
            char *seestir = new char [stidstring.length() + 1];
            std::strcpy(seestir, stidstring.c_str());

            dbg::qStdOut() << "Revised chatline=" << chatline << "\n";

            ff->printMessageToCurrentTab(seestir);
            auto settings = settings::getSettings();
            if(settings->value(ECHO_FLAG, true).toBool())
            {
                ff->requestSendChannelTextMsg(this->schid, seestir, 1, nullptr);
            }
            ff->freeMemory(nickname);
            delete[] seestir;
        }
    }
    if(flac != nullptr)
    {
        delete flac;
    }
    emit finished();
}

sdefdata::~sdefdata()
{
    if(byt)
    {
        delete byt;
    }
}
