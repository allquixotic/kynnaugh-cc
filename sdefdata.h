#ifndef SDEFDATA_H
#define SDEFDATA_H

#include <QtCore>
#include "sampledef.h"

class sdefdata : public QObject
{
    Q_OBJECT
public:
    sdefdata(QByteArray *b, qint32 chan, quint64 sch, anyID cli);
    ~sdefdata();
private:
    QByteArray *byt;
    qint32 channels;
    quint64 schid;
    anyID clientID;
    QBuffer buf;
    static QMutex lck;
public Q_SLOTS:
    void start();

Q_SIGNALS:
    void finished();
};

#endif // SDEFDATA_H
