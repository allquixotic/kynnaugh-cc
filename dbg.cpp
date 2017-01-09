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

void dbg::writeToFile(QBuffer *buf, QString ext)
{
#ifdef KYNNAUGH_DEBUG
    QString tmpfilepath = QStandardPaths::writableLocation(QStandardPaths::TempLocation) + QDir::separator() + "kynnaugh-" + QString::number(QDateTime::currentMSecsSinceEpoch()) + ext;
    QFile tmpfile(tmpfilepath);
    dbg::qStdOut() << "convert::dbgWriteToFile: writing outbuf to " << tmpfilepath << "\n";
    tmpfile.open(QIODevice::WriteOnly);
    qint64 nbytes = tmpfile.write(buf->data());
    tmpfile.flush();
    tmpfile.close();
    dbg::qStdOut() << "convert::dbgWriteToFile: wrote " << QString::number(nbytes) << " bytes to " << tmpfilepath << ".\n";
#endif
}

void dbg::writeToFile(char *c, qint64 len, QString ext)
{
#ifdef KYNNAUGH_DEBUG
    QBuffer *buf = new QBuffer();
    buf->open(QIODevice::WriteOnly);
    buf->write(c, len);
    dbg::writeToFile(buf, ext);
    delete buf;
#endif
}
