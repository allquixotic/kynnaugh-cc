#include "dbg.h"

QTextStream& dbg::qStdOut()
{
    ;
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
