#This file is part of kynnaugh-cc.

#Kynnaugh-cc is free software: you can redistribute it and/or modify
#it under the terms of the Apache License, version 2.0 as published by
#the Apache Software Foundation, either version 2 of the License, or
#(at your option) any later version.

#Foobar is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#Apache License, version 2.0 for more details.

#You should have received a copy of the Apache License, version 2.0
#along with kynnaugh-cc.  If not, see <https://www.apache.org/licenses/LICENSE-2.0>.

QT       -= gui

TARGET = kynnaugh
TEMPLATE = lib

CONFIG += warn_off

DEFINES += KYNNAUGH_LIBRARY

win32 {
    DEFINES += "_WIN32_WINNT=0x0600"
    DEFINES += "WINVER=0x0600"
}

INCLUDEPATH += C:\gstreamer\1.0\x86_64\include\Qt5GStreamer
INCLUDEPATH += C:\gstreamer\1.0\x86_64\include\gstreamer-1.0
INCLUDEPATH += C:\gstreamer\1.0\x86_64\include\glib-2.0
INCLUDEPATH += C:\gstreamer\1.0\x86_64\include
INCLUDEPATH += $$PWD

LIBS += -lgrpc++ -lgrpc -lgpr -lz
LIBS += -LC:\gstreamer\1.0\x86_64\lib -LC:\gstreamer\1.0\x86_64\bin -lQt5GStreamer-1.0 -lQt5GStreamerUtils-1.0 -lQt5GLib-2.0 -lgstreamer-1.0 -lglib-2.0
LIBS += -llibprotobuf
LIBS += -llibeay32 -lssleay32 -lws2_32

# DEFINES += QT_NO_KEYWORDS

SOURCES += kynnaugh.cpp \
    sampledef.cpp \
    convert.cpp \
    speechrec.cpp \
    google/cloud/speech/v1beta1/cloud_speech.grpc.pb.cc \
    google/cloud/speech/v1beta1/cloud_speech.pb.cc \
    google/longrunning/operations.grpc.pb.cc \
    google/longrunning/operations.pb.cc \
    google/rpc/code.grpc.pb.cc \
    google/rpc/code.pb.cc \
    google/rpc/error_details.grpc.pb.cc \
    google/rpc/error_details.pb.cc \
    google/rpc/status.grpc.pb.cc \
    google/rpc/status.pb.cc \
    google/api/annotations.grpc.pb.cc \
    google/api/annotations.pb.cc \
    google/api/http.grpc.pb.cc \
    google/api/http.pb.cc \
    google/api/httpbody.grpc.pb.cc \
    google/api/httpbody.pb.cc

HEADERS += kynnaugh.h\
        kynnaugh_global.h \
    plugin_definitions.h \
    ts3_functions.h \
    teamspeak/clientlib_publicdefinitions.h \
    teamspeak/public_definitions.h \
    teamspeak/public_errors_rare.h \
    teamspeak/public_errors.h \
    teamspeak/public_rare_definitions.h \
    teamlog/logtypes.h \
    sampledef.h \
    convert.h \
    speechrec.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    generated/google/google/logging/README.md \
    generated/google/google/rpc/README.md \
    generated/google/type/README.md
