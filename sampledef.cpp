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

#include "sampledef.h"
#include "kynnaugh.h"
#include "dbg.h"
#include "sdefdata.h"

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
    this->samples.append((const char*) more, count * (sizeof(short) / sizeof(char)));
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
        dbg::qStdOut() << "Expired: " << this->clientID << "\n";

        QThread *worker = nullptr;

        //The broad brush strokes glue: pull it all together; FLAC encoding and speech recognition in a few lines!
        if(this->samples.size() == 0)
        {
            dbg::qStdOut() << "Zero-length samples yet expired?\n";
        }
        else
        {
            //Converting the data to FLAC and then uploading it to Google Cloud Speech and getting a response takes a few seconds.
            //We don't want to block while that's happening; in fact, we're happy to let this go on in the background while we free up
            //the user's VoiceData thread back to TeamSpeak.
            QByteArray *bacopy = new QByteArray(this->samples);
            worker = new QThread(nullptr);
            sdefdata *sdf = new sdefdata(bacopy, channels, schid, clientID);
            sdf->moveToThread(worker);
            connect(worker, SIGNAL(started()), sdf, SLOT(start()));
            connect(sdf, SIGNAL(finished()), worker, SLOT(quit()));
            connect(sdf, SIGNAL(finished()), sdf, SLOT(deleteLater()));
            connect(sdf, SIGNAL(finished()), worker, SLOT(deleteLater()));
        }

        this->samples.clear();
        this->spoonTooBig = false;
        QDateTime nul;
        this->lastUpdated = nul;
        this->checker.exit(0);

        if(worker)
        {
            worker->start();
        }
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
