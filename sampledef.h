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
    quint64 schid;
    anyID clientID;
    QByteArray samples;
    qint32 channels;
    std::tuple<quint64, anyID, qint32> key;
    QReadWriteLock lock;
    QDateTime lastUpdated;
    QThread checker;
    QTimer timer;
    convert conv;
    speechrec rec;
    bool spoonTooBig;
};

#endif // SAMPLEDEF_H
