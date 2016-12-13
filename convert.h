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

class initonce
{
public:
    initonce()
    {
        QGst::init();
    }
};

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
    static initonce ionce;
};

#endif // CONVERT_H
