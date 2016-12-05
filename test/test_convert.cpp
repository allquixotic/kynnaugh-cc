#include <test_convert.h>
#include <iostream>

TestConvert::TestConvert()
    : conv(this)
{

}

void TestConvert::testConvertMono()
{
    #if 0
    testConvertGeneric(false);
    #endif
}


void TestConvert::testConvertStereo()
{
    testConvertGeneric(true);
}

void TestConvert::testConvertGeneric(bool ster)
{
    stereo = ster;


#if 0
    QString som = (stereo ? "stereo" : "mono");
    QString ext = ".raw";
    QString filename = "bensound-littleidea-48k-s16le-" + som + ext;
#endif
    QString filename = "stereo.wav";
    QFile sourcedata(filename, this);

    qDebug() << "*=@*=@*=@*=@Before conv.convertRawToFlac() with filename=" << filename;
    conv.convertRawToFlac(&sourcedata, (stereo ? 2 : 1));

    connect(conv.avt,&AVTranscoder::stopped, this, &TestConvert::stopped);
}

void TestConvert::stopped()
{
    AVPlayer player(this);
    qDebug() << "*=@*=@*=@*=@After conv.convertRawToFlac() with stereo=" << stereo;
    QVERIFY2(conv.retval.length() > 0, "Returned FLAC buffer size was zero!"); //Always fails here.
    QBuffer playbuf(this);
    playbuf.setData(conv.retval);
    player.setIODevice(&playbuf);
    qDebug() << "*=@*=@*=@*=@Before player.play()";
    player.play();
    qDebug() << "*=@*=@*=@*=@Got to end of testConvertGeneric with stereo=" << stereo;
}

int main(int argc, char **argv)
{
    QCoreApplication *qca = QCoreApplication::instance();
    if(qca == NULL)
        qca = new QCoreApplication(argc, argv, 0);

    TestConvert tc;

    tc.testConvertStereo();

    return qca->exec();
}
