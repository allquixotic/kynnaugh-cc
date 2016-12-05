#ifndef TEST_CONVERT_H
#define TEST_CONVERT_H

#include <QtTest>
#include <QtAV>
#include <../convert.h>

using namespace QtAV;

class TestConvert : public QObject
{
    Q_OBJECT

public:
    TestConvert();
    void testConvertMono();
    void testConvertStereo();

public slots:
    void stopped();

//private slots:


private:
    void testConvertGeneric(bool ster);
    convert conv;
    bool stereo;
};


#endif // TEST_CONVERT_H
