/*
This file is part of kynnaugh-cc.

Kynnaugh-cc is free software: you can redistribute it and/or modify
it under the terms of the Apache License, version 2.0 as published by
the Apache Software Foundation, either version 2 of the License, or
(at your option) any later version.

Kynnaugh-cc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
Apache License, version 2.0 for more details.

You should have received a copy of the Apache License, version 2.0
along with kynnaugh-cc.  If not, see <https://www.apache.org/licenses/LICENSE-2.0>.
*/

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
KYNNAUGHSHARED_EXPORT int ts3plugin_offersConfigure();
KYNNAUGHSHARED_EXPORT void ts3plugin_configure(void* handle, void* qParentWidget);

}

namespace std {
    inline uint qHash(const std::tuple<quint64, anyID, qint32> &key, uint seed);
}

#endif // KYNNAUGH_GLOBAL_H
