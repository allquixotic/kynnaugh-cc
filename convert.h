#ifndef CONVERT_H
#define CONVERT_H

#include <QtCore>
#include <QtAV>
#include <QtAV/AVTranscoder.h>

using namespace QtAV;

class convert : public QObject
{
    Q_OBJECT
public:
    explicit convert(QObject *parent = 0);
    void convertRawToFlac(QIODevice *data, qint32 channels);
    AVTranscoder *avt;
    AVPlayer *player;
    QByteArray retval;

};

#endif // CONVERT_H
