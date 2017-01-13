#ifndef SETTINGS_H
#define SETTINGS_H

#include <memory>
#include <QtCore>

class settings : public QObject
{
    Q_OBJECT
public:
    static std::unique_ptr<QSettings> getSettings();

signals:

public slots:
};

#endif // SETTINGS_H
