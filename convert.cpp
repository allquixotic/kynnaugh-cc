#include "convert.h"

#include <QtTest/QSignalSpy>

#define QQ qDebug() << "convert::convertRawToFlac" << i++;

static void write_little_endian(quint32 word, qint32 num_bytes, QDataStream *stream)
{
    quint32 buf;
    const char *rbuf;
    while(num_bytes>0)
    {   buf = word & 0xff;
        rbuf = (const char*) &buf;
        stream->writeRawData(rbuf, 1);
        num_bytes--;
        word >>= 8;
    }
}

/* information about the WAV file format from
    http://ccrma.stanford.edu/courses/422/projects/WaveFormat/
 */
static void write_wav(QByteArray *wav_file, quint32 channels)
{
    QByteArray header;
    QDataStream stream(&header, QIODevice::WriteOnly);
    quint32 length = wav_file->length() * 2; //Each "sample" is one signed 16-bit integer; one sample per channel
    quint32 samplerate = 48000;
    quint32 bytes_per_sample = 2;
    quint32 byte_rate;

    byte_rate = samplerate * channels * bytes_per_sample;

    /* write RIFF header */
    const char *riff = "RIFF", *wave = "WAVE", *fmt = "fmt ", *datastr = "data";
    stream.writeRawData(riff, 4);

    write_little_endian(36 + bytes_per_sample * length * channels, 4, &stream);
    stream.writeRawData(wave, 4);

    /* write fmt  subchunk */
    stream.writeRawData(fmt, 4);
    write_little_endian(16, 4, &stream);   /* SubChunk1Size is 16 */
    write_little_endian(1, 2, &stream);    /* PCM is format 1 */
    write_little_endian(channels, 2, &stream);
    write_little_endian(samplerate, 4, &stream);
    write_little_endian(byte_rate, 4, &stream);
    write_little_endian(channels*bytes_per_sample, 2, &stream);  /* block align */
    write_little_endian(8*bytes_per_sample, 2, &stream);  /* bits/sample */

    /* write data subchunk */
    stream.writeRawData(datastr, 4);
    write_little_endian(bytes_per_sample * length * channels, 4, &stream);

    wav_file->prepend(header);

    qDebug() << "Header (hex):" << header.toHex();
    qDebug() << "wav_file's initial length in bytes was" << (length/2) << "and it's now" << wav_file->length();
}

convert::convert(QObject *parent) : QObject(parent)
{

}

//Assume `QByteArray` contains Signed 16-bit LE PCM samples at 48 kHz
void convert::convertRawToFlac(QIODevice *data, qint32 channels)
{
    QByteArray srcdata;
    QBuffer retbuf(&this->retval, this);
    this->avt = new AVTranscoder(this);
    this->player = new AVPlayer();
    QVariantHash muxopt, avfopt, encopt;
    AudioEncoder *enc;
    AudioFormat enc_avformat, dec_avformat;
    int i = 1;

    avt->setAsync(true);

    QQ

    if(!data->isOpen())
    {
        data->open(QIODevice::ReadOnly);
    }

    srcdata = data->readAll();

    //write_wav(&srcdata, (quint32) channels);

    QQ

    retbuf.open(QIODevice::ReadWrite);

    QQ

    encopt["compression_level"] = 12;

    QQ

    dec_avformat.setSampleFormat(AudioFormat::SampleFormat::SampleFormat_Signed16);
    dec_avformat.setChannels(channels);
    dec_avformat.setSampleRate(48000);

    QQ

    enc_avformat.setChannels(1);
    enc_avformat.setSampleRate(16000);
    enc_avformat.setSampleFormat(AudioFormat::SampleFormat::SampleFormat_Signed16);

    QQ

    QBuffer srcdata_buffer(&srcdata);
    srcdata_buffer.open(QIODevice::ReadOnly);
    player->setIODevice(&srcdata_buffer);
    player->audio()->setBackends(QStringList() << QString::fromLatin1("null"));
    //player.audio()->setAudioFormat(dec_avformat);
    player->setAsyncLoad(false);

    QQ

    avt->createAudioEncoder();
    enc = avt->audioEncoder();

    qDebug() << "is enc NULL?" << (enc == NULL);

    QQ

    enc->setAudioFormat(enc_avformat);

    QQ

    enc->setCodecName(QString("flac"));

    //QQ

    //enc->setOptions(encopt);

    QQ

    avt->setMediaSource(player);

    QQ    qDebug() << "Is the AVTranscoder running AFTER calling start() on it (BEFORE AVPlayer::play())?" << (avt->isRunning()) << i++;
    qDebug() << "Is the AVPlayer playing AFTER calling start() on the AVTranscoder?" << (player->isPlaying()) << i++;

    avt->setOutputMedia(&retbuf);

    qDebug() << "Is the AVTranscoder running BEFORE calling start() on it?" << (avt->isRunning()) << i++;
    qDebug() << "Is the AVPlayer playing BEFORE calling start() on the AVTranscoder?" << (player->isPlaying()) << i++;
    avt->start();

    qDebug() << "Is the AVTranscoder running AFTER calling start() on it (BEFORE AVPlayer::play())?" << (avt->isRunning()) << i++;
    qDebug() << "Is the AVPlayer playing AFTER calling start() on the AVTranscoder?" << (player->isPlaying()) << i++;

    player->play();

    qDebug() << "Is the AVTranscoder running AFTER calling play() on the AVPlayer?" << (avt->isRunning()) << i++;
    qDebug() << "Is the AVPlayer playing AFTER calling play() on it?" << (player->isPlaying()) << i++;

    //avt.start();
    //qDebug() << "Is the AVTranscoder running AFTER calling start() on it (AFTER AVPlayer::play())?" << (avt->isRunning()) << i++;
    //qDebug() << "Is the AVPlayer playing AFTER calling start() on the AVTranscoder?" << (player->isPlaying()) << i++;

    QQ

    qDebug() << "retval.length()=" << retval.length();

    //return retval;
}
