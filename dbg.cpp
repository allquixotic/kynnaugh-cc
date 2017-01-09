#include "dbg.h"

#ifdef KYNNAUGH_DEBUG
QTextStream& dbg::qStdOut()
{
    static QFile f(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + QDir::separator() + "kynnaugh-cc-log.txt");
    if(!f.isOpen())
    {
        f.open(QIODevice::WriteOnly | QIODevice::Text);
    }
    static QTextStream ts( &f );
    ts.flush();
    f.flush();
    return ts;
}


#else

dbg dbg::instance;

dbg& dbg::qStdOut() { return dbg::instance; }
dbg& dbg::operator<<(QChar c) { return dbg::instance; }
dbg& dbg::operator<<(signed short i) { return dbg::instance; }
dbg& dbg::operator<<(float f) { return dbg::instance; }
dbg& dbg::operator<<(const QString & string) { return dbg::instance; }
dbg& dbg::operator<<(char c) { return dbg::instance; }
dbg& dbg::operator<<(unsigned short i) { return dbg::instance; }
dbg& dbg::operator<<(signed int i) { return dbg::instance; }
dbg& dbg::operator<<(unsigned int i) { return dbg::instance; }
dbg& dbg::operator<<(signed long i) { return dbg::instance; }
dbg& dbg::operator<<(unsigned long i) { return dbg::instance; }
dbg& dbg::operator<<(qlonglong i) { return dbg::instance; }
dbg& dbg::operator<<(qulonglong i) { return dbg::instance; }
dbg& dbg::operator<<(double f) { return dbg::instance; }
dbg& dbg::operator<<(const QByteArray & array) { return dbg::instance; }
dbg& dbg::operator<<(const char * string) { return dbg::instance; }
dbg& dbg::operator<<(const void * ptr) { return dbg::instance; }

#endif
