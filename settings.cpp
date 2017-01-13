#include "settings.h"

std::unique_ptr<QSettings> settings::getSettings()
{
    QSettings *sett = new QSettings(QSettings::IniFormat, QSettings::UserScope, "rootaccessorg", "kynnaugh-cc", nullptr);
    std::unique_ptr<QSettings> retval(sett);
    return retval;
}
