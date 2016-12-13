#include <test_convert.h>
#include <iostream>
#include <QGst/Parse>
#include <QGst/Message>
#include <QGst/Buffer>
#include <QGst/Bus>
#include <glib.h>
#include <gst/gstbuffer.h>

TestConvert::TestConvert()
    : conv(nullptr)
{

}

void TestConvert::testConvertMono()
{
    testConvertGeneric(false);
}


void TestConvert::testConvertStereo()
{
    testConvertGeneric(true);
}

void TestConvert::testConvertGeneric(bool ster)
{
    stereo = ster;

    QString som = (stereo ? "stereo" : "mono");
    QString ext = ".raw";
    QString filename = "bensound-littleidea-48k-s16le-" + som + ext;
    QFile sourcedata(filename, this);
    BusPtr vroom;

    qDebug() << "*=@*=@*=@*=@Before conv.convertRawToFlac() with filename=" << filename;
    conv.convertRawToFlac(&sourcedata, (stereo ? 2 : 1));

    qDebug() << "conv.convertRawToFlac() returned; retval has size in bytes=" << conv.retval.size();

    qDebug() << "Writing data to blah.flac";
    QString uri = "file:///";
    QFile writedata("blah.flac", this);
    writedata.open(QIODevice::WriteOnly);
    writedata.write(conv.retval.data(), conv.retval.size());
    writedata.flush();
    writedata.close();
    qDebug() << "Data written to blah.flac!";
    QFileInfo qfi(writedata);
    uri += qfi.absoluteFilePath();

    ElementPtr pipeline_ele = Parse::launch(QString("playbin uri=") + uri);
    PipelinePtr pipeline = pipeline_ele.dynamicCast<Pipeline>();
    vroom = pipeline->bus();
    pipeline->setState(QGst::StatePlaying);


    MessagePtr mp;
    do
    {
        mp = vroom->pop(ClockTime::fromSeconds(10));
        if(!mp.isNull())
        {
            if(mp->type() == QGst::MessageEos)
            {
                qDebug() << "Got EOS message on bus!";
            }
            else
            {
                if(mp->type() == QGst::MessageError)
                {
                    qDebug() << "Got ERROR message on bus!";
                }
            }
        }
        else
        {
            qDebug() << "Popped a NULL message off the bus. Hmm...";
        }
    }
    while(mp.isNull() || (!mp.isNull() && mp->type() != QGst::MessageEos && mp->type() != QGst::MessageError));

    qDebug() << "Done the bus message pump loop...";

    pipeline->setState(QGst::StateNull);
}

QTEST_MAIN(TestConvert)
