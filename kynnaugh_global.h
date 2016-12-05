#ifndef KYNNAUGH_GLOBAL_H
#define KYNNAUGH_GLOBAL_H

#include <QtCore>
#include <teamspeak/public_definitions.h>
#include <tuple>

#if defined(KYNNAUGH_LIBRARY)
#  define KYNNAUGHSHARED_EXPORT Q_DECL_EXPORT
#else
#  define KYNNAUGHSHARED_EXPORT Q_DECL_IMPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Required functions */
KYNNAUGHSHARED_EXPORT const char *ts3plugin_name();
KYNNAUGHSHARED_EXPORT const char *ts3plugin_version();
KYNNAUGHSHARED_EXPORT int ts3plugin_apiVersion();
KYNNAUGHSHARED_EXPORT const char *ts3plugin_author();
KYNNAUGHSHARED_EXPORT const char *ts3plugin_description();
KYNNAUGHSHARED_EXPORT void ts3plugin_setFunctionPointers(const struct TS3Functions funcs);
KYNNAUGHSHARED_EXPORT int ts3plugin_init();
KYNNAUGHSHARED_EXPORT void ts3plugin_shutdown();
KYNNAUGHSHARED_EXPORT void
ts3plugin_onEditPlaybackVoiceDataEvent(uint64 serverConnectionHandlerID, anyID clientID, short *samples,
                                       int sampleCount, int channels);
KYNNAUGHSHARED_EXPORT void ts3plugin_freeMemory(void* data);
KYNNAUGHSHARED_EXPORT int ts3plugin_requestAutoload();
KYNNAUGHSHARED_EXPORT void ts3plugin_registerPluginID(const char* id);

}

namespace std {
    inline uint qHash(const std::tuple<quint64, anyID, qint32> &key, uint seed);
}

#endif // KYNNAUGH_GLOBAL_H
