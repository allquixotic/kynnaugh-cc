#include "sampledef.h"

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

        //Encode and transcribe

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
