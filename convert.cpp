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

#include "convert.h"

#include <QGst/ElementFactory>
#include <QGlib/Error>
#include <QGlib/Connect>
#include <QGst/Bus>
#include <QGst/Parse>
#include <QGst/Message>
#include <QGst/Buffer>
#include <glib.h>
#include <gst/gstbuffer.h>

#define SP qDebug() << "convert::setupPipeline()" << i++;
#define CRTF qDebug() << "convert::convertRawToFlac()" << i++;

bool convert::inited = false;
QMutex convert::initLock;

convert::convert()
    : QObject(nullptr), lock(QReadWriteLock::Recursive), data(NULL), channels(0)
{
    initLock.lock();
    if(!inited)
    {
        QGst::init();
        qDebug() << "GStreamer has been inited in convert constructor.";
        inited = true;
    }
    initLock.unlock();

}

//Assume `data` contains Signed 16-bit LE PCM samples at 48 kHz
QByteArray convert::convertRawToFlac(QIODevice *dat, qint32 channes)
{
    retval.clear();
    int i = 0;
    QWriteLocker locker(&lock);
    this->data = dat;
    this->channels = channes;
    CRTF
    setupPipeline();
    CRTF
    if(!this->data->isOpen())
    {
        this->data->open(QIODevice::ReadOnly);
    }
    QByteArray sourcedata = this->data->readAll();
    qDebug() << "sourcedata has length " << sourcedata.size();
    BufferPtr qbuf = Buffer::create(sourcedata.size());
    GstBuffer *buf = static_cast<GstBuffer*>(qbuf);
    SamplePtr sam;
    gst_buffer_fill(buf, 0, static_cast<gconstpointer>(sourcedata.data()), sourcedata.size());
    qDebug() << "GstBuffer has size " << qbuf->size();

    qDebug() << "Setting state to READY";
    pipeline->setState(QGst::StateReady);
    qDebug() << "READY set; setting state to PAUSED";
    pipeline->setState(QGst::StatePaused);
    qDebug() << appsrc->pushBuffer(qbuf);
    qDebug() << "pushed buffer; setting state to PLAYING";
    pipeline->setState(QGst::StatePlaying);
    qDebug() << "Set state to PLAYING";
    appsrc->endOfStream();
    qDebug() << "Sending EOS";
    CRTF
    do
    {
        sam = appsink->pullSample();
        if(!sam.isNull())
        {
            BufferPtr bp = sam->buffer();
            quint32 sz = bp->size();
            if(sz > 0)
            {
                gpointer raw = malloc(sz);
                if(raw != NULL)
                {
                    bp->extract(0, raw, sz);
                    this->retval.append(static_cast<const char*>(raw), sz);
                    free(raw);
                }
            }
        }
    } while(!sam.isNull() && !appsink->isEos());
    CRTF
    this->pipeline->setState(QGst::StateReady);
    qDebug() << "FLAC encoding pipeline state set back to ready because we're done";
    CRTF
    return retval;
}

void convert::setupPipeline()
{
    int i = 0;
    if(pipeline.isNull())
    {
        SP
        PipelinePtr pipe;
#if 0
        QString pipetext = QString("appsrc name=\"a\""
                                   " caps=\"audio/x-raw,format=S16LE,rate=48000,layout=interleaved,channels=%1\" ! "
                                   "audioconvert name=\"b\" ! "
                                   "audioresample name=\"c\" ! "
                                   "audio/x-raw,format=S16LE,rate=16000,channels=1,layout=interleaved ! "
                                   "flacenc name=\"d\" !"
                                   "appsink name=\"e\" caps=\"audio/x-flac\" sync=true")
                           .arg(this->channels);
#endif

        QString pipetext = QString("appsrc name=\"a\""
                                   " caps=\"audio/x-raw,format=S16LE,rate=48000,layout=interleaved,channels=%1\" ! "
                                   "audioconvert name=\"b\" ! "
                                   "audioresample name=\"c\" ! "
                                   "audio/x-raw,format=S16LE,rate=48000,channels=1,layout=interleaved ! "
                                   "flacenc name=\"d\" !"
                                   "appsink name=\"e\" caps=\"audio/x-flac\" sync=true")
                           .arg(this->channels);

        qDebug() << "Pipeline text: " << pipetext;
        pipeline = Parse::launch(pipetext);
        SP
        pipe = pipeline.dynamicCast<Pipeline>();
        SP
        appsrc = new ApplicationSource();
        appsrc->setElement(pipe->getElementByName("a"));
        appsrc->enableBlock(true);
        appsrc->setLive(false);
        appsrc->setStreamType(QGst::AppStreamTypeStream);
        appsrc->setCaps(Caps::fromString(QString("audio/x-raw,format=S16LE,rate=48000,layout=interleaved,channels=%1").arg(this->channels)));
        appsrc->setMaxBytes(1073741824);
        SP
        audioconvert = pipe->getElementByName("b");

        flacenc = pipe->getElementByName("d");

        appsink = new ApplicationSink();
        appsink->setElement(pipe->getElementByName("e"));
        appsink->enableDrop(false);
        appsink->setCaps(Caps::fromString("audio/x-flac"));
        appsink->setMaxBuffers(1073741824);
        SP
    }
}

convert::~convert()
{
    if(!this->pipeline.isNull())
    {
        this->pipeline->setState(QGst::StateNull);
    }
}

