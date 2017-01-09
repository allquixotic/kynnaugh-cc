#ifndef SDEFDATA_H
#define SDEFDATA_H

#include <QtCore>
#include "sampledef.h"

class sdefdata : public QObject
{
    Q_OBJECT
public:
    QBuffer *buf;
    qint32 channels;
    quint64 schid;
    anyID clientID;
    sdefdata(QBuffer *b, qint32 chan, quint64 sch, anyID cli);
    ~sdefdata();
public Q_SLOTS:
    void start();

Q_SIGNALS:
    void finished();
};

#endif // SDEFDATA_H
