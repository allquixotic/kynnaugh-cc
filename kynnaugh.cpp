/*
/*TeamSpeak 3 plugin development kit
Copyright (c) 2008-2016 TeamSpeak Systems GmbH
Copyright (c) 2016 Sean McNamara <smcnam@gmail.com>

Available to the general public at https://www.teamspeak.com/downloads with no specified license.
The author of kynnaugh-cc does not claim to license this file under the Apache License, version 2.0.
This file is a derivative work of the example in the Plugin SDK.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <teamspeak/public_definitions.h>
#include <plugin_definitions.h>
#include <ts3_functions.h>
#include <kynnaugh.h>
#include <sampledef.h>
#include <QtCore>
#include <tuple>
#include "dbg.h"
#include "speechrec.h"

#define PLUGIN_API_VERSION 21
#define PATH_BUFSIZE 512
#define COMMAND_BUFSIZE 128
#define INFODATA_BUFSIZE 128
#define SERVERINFO_BUFSIZE 256
#define CHANNELINFO_BUFSIZE 512
#define RETURNCODE_BUFSIZE 128

struct TS3Functions *ts3func::funcs = nullptr;
static struct TS3Functions ts3Functions;
static QString *pluginID = NULL;
static QHash<std::tuple<quint64, anyID, qint32>, sampledef*> sampledefs = QHash<std::tuple<quint64, anyID, qint32>, sampledef*>();

#define STATIC_STRING(x) static QString var = x; static QByteArray arr = var.toUtf8(); return arr.constData();

/*********************************** Required functions ************************************/
/*
 * If any of these required functions is not implemented, TS3 will refuse to load the plugin
 */

/* Unique name identifying this plugin */
const char* ts3plugin_name() {
    STATIC_STRING("Kynnaugh")
}

/* Plugin version */
const char* ts3plugin_version() {
    STATIC_STRING("1.0")
}

/* Plugin API version. Must be the same as the clients API major version, else the plugin fails to load. */
int ts3plugin_apiVersion() {
    return PLUGIN_API_VERSION;
}

/* Plugin author */
const char* ts3plugin_author() {
    STATIC_STRING("Sean McNamara / Coorbin Faydedar <smcnam@gmail.com>")
}

/* Plugin description */
const char* ts3plugin_description() {
    STATIC_STRING("Speech recognition and text to speech for deaf users.")
}

/* Set TeamSpeak 3 callback functions */
void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
    ts3Functions = funcs;
    ts3func::funcs = &ts3Functions;
}

/*
 * Custom code called right after loading the plugin. Returns 0 on success, 1 on failure.
 * If the function returns 1 on failure, the plugin will be unloaded again.
 */
int ts3plugin_init() {
    char appPath[PATH_BUFSIZE];
    char resourcesPath[PATH_BUFSIZE];
    char configPath[PATH_BUFSIZE];
    char pluginPath[PATH_BUFSIZE];

    /* Your plugin init code here */
    printf("KYNNAUGH PLUGIN: init\n");

    /* Example on how to query application, resources and configuration paths from client */
    /* Note: Console client returns empty string for app and resources path */
    ts3Functions.getAppPath(appPath, PATH_BUFSIZE);
    ts3Functions.getResourcesPath(resourcesPath, PATH_BUFSIZE);
    ts3Functions.getConfigPath(configPath, PATH_BUFSIZE);
    ts3Functions.getPluginPath(pluginPath, PATH_BUFSIZE);

    //This code hacks around situations (only possible on OS X and Windows) where two versions of Qt are loaded in the same address space.
    //Teamspeak's own Qt creates its own QApplication, but we have to make *another* if "our" Qt isn't TeamSpeak's Qt.
    //This *never* occurs on Linux because of the lack of a "Side-by-side" library compatibility subsystem.
    int argc = 1;
    char *first = "a";
    char **argv = &first;
    QCoreApplication *app = QCoreApplication::instance();
    if(app == nullptr)
    {
        app = new QCoreApplication(argc, argv);
    }

    //Here's where we initialize QSettings. Can't use it before now!
    QCoreApplication::setOrganizationName("rootaccessorg");
    QCoreApplication::setApplicationName("kynnaugh-cc");


#if defined(_WIN32) && defined(KYNNAUGH_DEBUG)
    //Redirect stdout and stderr to a log file because TS handles them weirdly/badly on Windows
    QString stdoutlogfile = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + QDir::separator() + "kynnaugh-cc-stdout-log.txt";
    QString stderrlogfile = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + QDir::separator() + "kynnaugh-cc-stderr-log.txt";
    freopen(qPrintable(stdoutlogfile),"w",stdout);
    freopen(qPrintable(stderrlogfile),"w",stderr);
#endif

    return 0;  /* 0 = success, 1 = failure, -2 = failure but client will not show a "failed to load" warning */
    /* -2 is a very special case and should only be used if a plugin displays a dialog (e.g. overlay) asking the user to disable
     * the plugin again, avoiding the show another dialog by the client telling the user the plugin failed to load.
     * For normal case, if a plugin really failed to load because of an error, the correct return value is 1. */
}

/* Custom code called right before the plugin is unloaded */
void ts3plugin_shutdown() {
    /* Your plugin cleanup code here */
    qWarning("KYNNAUGH PLUGIN: shutdown\n");

    /*
     * Note:
     * If your plugin implements a settings dialog, it must be closed and deleted here, else the
     * TeamSpeak client will most likely crash (DLL removed but dialog from DLL code still open).
     */

    /* Free pluginID if we registered it */
    if(pluginID) {
        free(pluginID);
        pluginID = NULL;
    }
}

/*
 * If the plugin wants to use error return codes, plugin commands, hotkeys or menu items, it needs to register a command ID. This function will be
 * automatically called after the plugin was initialized. This function is optional. If you don't use these features, this function can be omitted.
 * Note the passed pluginID parameter is no longer valid after calling this function, so you must copy it and store it in the plugin.
 */
void ts3plugin_registerPluginID(const char* id) {
    qInstallMessageHandler(0);
    pluginID = new QString(id);
    dbg::qStdOut() << "KYNNAUGH PLUGIN: registerPluginID: " << pluginID;
}

/* Required to release the memory for parameter "data" allocated in ts3plugin_infoData and ts3plugin_initMenus */
void ts3plugin_freeMemory(void* data) {
    free(data);
}

/*
 * Plugin requests to be always automatically loaded by the TeamSpeak 3 client unless
 * the user manually disabled it in the plugin dialog.
 * This function is optional. If missing, no autoload is assumed.
 */
int ts3plugin_requestAutoload() {
    return 1;  /* 1 = request autoloaded, 0 = do not request autoload */
}

void ts3plugin_onEditPlaybackVoiceDataEvent(uint64 serverConnectionHandlerID, anyID clientID, short *samples,
                                       int sampleCount, int channels) {

    //The below logging message is printed _very_ frequently; only use if you're not sure if this callback is being called at all.
    //ts3Functions.printMessageToCurrentTab("ts3plugin_onEditPlaybackVoiceDataEvent");

    std::tuple<quint64, anyID, qint32> key = sampledef::getKey(serverConnectionHandlerID, clientID, channels);
    if(sampledefs.contains(key))
    {
        sampledefs[key]->update(samples, sampleCount);
    }
    else
    {
        char *nickname;
        ts3Functions.getClientVariableAsString(serverConnectionHandlerID, clientID, ClientProperties::CLIENT_NICKNAME, &nickname);
        dbg::qStdOut() << "KYNNAUGH PLUGIN: New sampledef for client #" << clientID << ", " << nickname << " with " << channels << " channels.\n";
        ts3Functions.freeMemory(nickname);
        sampledef *def = new sampledef(0, serverConnectionHandlerID, clientID, channels);
        sampledefs.insert(key, def);
        def->update(samples, sampleCount);
    }
}

namespace std
{
    inline uint qHash(const std::tuple<quint64, anyID, qint32> &key, uint seed = 0)
    {
        const quint64 &one = std::get<0>(key);
        const anyID   &two = std::get<1>(key);
        const qint32  &three = std::get<2>(key);

        return ::qHash(one, seed) ^ ::qHash(two, seed) ^ ::qHash(three, seed);
    }
}
