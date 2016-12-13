#ifndef TEST_CONVERT_H
#define TEST_CONVERT_H

#include <QtTest>
#include <../convert.h>

class TestConvert : public QObject
{
    Q_OBJECT

public:
    TestConvert();

private:
    void testConvertGeneric(bool ster);
    convert conv;
    bool stereo;

private slots:
    void testConvertMono();
    void testConvertStereo();
};


#endif // TEST_CONVERT_H
