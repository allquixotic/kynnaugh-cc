#ifndef DBG_H
#define DBG_H

#include <QtCore>

class dbg : public QObject
{
            Q_OBJECT
public:
    static QTextStream& qStdOut();
};

#endif // DBG_H
