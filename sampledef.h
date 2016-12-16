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

#ifndef SAMPLEDEF_H
#define SAMPLEDEF_H

#include <tuple>
#include <QtCore>
#include <teamspeak/public_definitions.h>
#include "convert.h"
#include "speechrec.h"

class sampledef : public QObject
{
    Q_OBJECT
public:
    sampledef(QObject *parent, quint64 s = 0, anyID c = 0, qint32 chan = 1);
    qint32 getChannels();
    QDateTime getLastUpdated();
    QByteArray getSamples();
    std::tuple<quint64, anyID, qint32> getKey();
    void update(const short* more, qint32 count);
    void clear();
    static std::tuple<quint64, anyID, qint32> getKey(quint64 schid, anyID clientID, qint32 channels);

public Q_SLOTS:
    void check();
    void threadStarted();
    void threadFinished();

private:
    static speechrec rec;
    quint64 schid;
    anyID clientID;
    QByteArray samples;
    qint32 channels;
    std::tuple<quint64, anyID, qint32> key;
    QReadWriteLock lock;
    QDateTime lastUpdated;
    QThread checker;
    QTimer timer;
    bool spoonTooBig;
};

#endif // SAMPLEDEF_H
