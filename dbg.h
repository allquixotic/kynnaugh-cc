#ifndef DBG_H
#define DBG_H

#include <QtCore>

#ifdef KYNNAUGH_DEBUG
class dbg : public QObject
{
            Q_OBJECT
public:
    static QTextStream& qStdOut();
};

#else

class dbg
{
public:
    static dbg &qStdOut();
    dbg& operator<<(QChar c);
    dbg& operator<<(signed short i);
    dbg& operator<<(float f);
    dbg& operator<<(const QString & string);
    dbg& operator<<(char c);
    dbg& operator<<(unsigned short i);
    dbg& operator<<(signed int i);
    dbg& operator<<(unsigned int i);
    dbg& operator<<(signed long i);
    dbg& operator<<(unsigned long i);
    dbg& operator<<(qlonglong i);
    dbg& operator<<(qulonglong i);
    dbg& operator<<(double f);
    dbg& operator<<(const QByteArray & array);
    dbg& operator<<(const char * string);
    dbg& operator<<(const void * ptr);
    private:
        static dbg instance;
};

#endif

#endif // DBG_H
