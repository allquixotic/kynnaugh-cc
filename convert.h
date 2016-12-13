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

#ifndef CONVERT_H
#define CONVERT_H

#include <QtCore>
#include <QGst/Pipeline>
#include <QGst/Bin>
#include <QGst/Element>
#include <QGst/Utils/ApplicationSink>
#include <QGst/Utils/ApplicationSource>
#include <QGst/Init>

using namespace QGst;
using namespace QGst::Utils;

class convert : public QObject
{
    Q_OBJECT
public:
    explicit convert(QObject *parent = 0);
    ~convert();
    void convertRawToFlac(QIODevice *dat, qint32 channes);
    QByteArray retval;
public Q_SLOTS:
    void threadStart();
private:
    static QMutex initLock;
    static bool inited;
    void setupPipeline();
    QThread *callingThread;
    QThread thread;
    QReadWriteLock lock;
    QIODevice *data;
    qint32 channels;
    ElementPtr pipeline;
    ElementPtr flacenc;
    ApplicationSource *appsrc;
    ElementPtr audioconvert;
    ApplicationSink *appsink;
};

#endif // CONVERT_H
