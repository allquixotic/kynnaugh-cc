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

#include "sampledef.h"
#include "kynnaugh.h"

speechrec sampledef::rec;

sampledef::sampledef(QObject *parent, quint64 s, anyID c, qint32 chan)
    : QObject(parent), schid(s), clientID(c), channels(chan), key(s, c, chan), lock(QReadWriteLock::Recursive),
      lastUpdated(), checker(this), timer(0), spoonTooBig(false)
{
    this->timer.setInterval(500);
    this->timer.setSingleShot(false);
    this->timer.setTimerType(Qt::CoarseTimer);
    this->timer.moveToThread(&this->checker);
    connect(&timer, &QTimer::timeout, this, &sampledef::check, Qt::DirectConnection);
    connect(&checker, &QThread::started, this, &sampledef::threadStarted, Qt::DirectConnection);
    connect(&checker, &QThread::finished, this, &sampledef::threadFinished, Qt::DirectConnection);
    this->checker.start(QThread::NormalPriority);
}

qint32 sampledef::getChannels()
{
    QReadLocker locker(&lock);
    return this->channels;
}

QByteArray sampledef::getSamples()
{
    QReadLocker locker(&lock);
    return this->samples;
}

std::tuple<quint64, anyID, qint32> sampledef::getKey()
{
    QReadLocker locker(&lock);
    return this->key;
}

std::tuple<quint64, anyID, qint32> sampledef::getKey(quint64 schid, anyID clientID, qint32 channels)
{
    return std::tuple<quint64, anyID, qint32>(schid, clientID, channels);
}

QDateTime sampledef::getLastUpdated()
{
    QReadLocker locker(&lock);
    return this->lastUpdated;
}

void sampledef::update(const short* more, qint32 count)
{
    QWriteLocker locker(&lock);
    this->samples.append((const char*) more, count);
    this->lastUpdated = QDateTime::currentDateTimeUtc();
    if(!this->checker.isRunning())
    {
        this->checker.start(QThread::NormalPriority);
    }

    if(this->samples.length() > (48000 * 57))
    {
        spoonTooBig = true;
    }
}

void sampledef::clear()
{
    QWriteLocker locker(&lock);
    this->samples.clear();
    this->spoonTooBig = false;
    QDateTime nul;
    this->lastUpdated = nul;
    this->checker.exit(0);
}

void sampledef::check()
{
    QWriteLocker locker(&lock);
    QDateTime curr = QDateTime::currentDateTimeUtc();

    if((this->lastUpdated.isValid() && this->lastUpdated.msecsTo(curr) >= 1250) || spoonTooBig)
    {
        printf("Expired: %d\n", this->clientID);

        //The broad brush strokes glue: pull it all together; FLAC encoding and speech recognition in a few lines!
        QBuffer buf(&this->samples);
        buf.open(QIODevice::ReadOnly);
        if(this->samples.size() == 0)
        {
            qDebug() << "Zero-length samples yet expired?";
        }
        else
        {
            convert conv;
            QByteArray flac = conv.convertRawToFlac(&buf, this->channels);
            if(flac.size() == 0)
            {
                qDebug() << "No FLAC samples returned, yet number of samples was greater than 0!";
            }
            else
            {
                qDebug() << "FLAC contains" << flac.size() << "bytes";
                QString chatline = rec.recognize(flac.data(), flac.size());
                qDebug() << "Returned from rec.recognize()!";
                qDebug() << "Saying" << chatline;
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
                    qDebug() << "Revised chatline=" << chatline;
                    const std::string stidstring = chatline.toStdString();
                    char *seestir = new char [stidstring.length() + 1];
                    std::strcpy(seestir, stidstring.c_str());

                    ff->printMessageToCurrentTab(seestir);
                    ff->requestSendChannelTextMsg(this->schid, seestir, 1, nullptr);
                    ff->freeMemory(nickname);
                    delete[] seestir;
                }
            }
        }

        this->samples.clear();
        this->spoonTooBig = false;
        QDateTime nul;
        this->lastUpdated = nul;
        this->checker.exit(0);
    }
}

void sampledef::threadStarted()
{
    this->timer.start();
}

void sampledef::threadFinished()
{
    this->timer.stop();
}
