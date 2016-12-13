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

QT += testlib
TEMPLATE = app
TARGET = test
INCLUDEPATH += .
CONFIG += debug
# Input
SOURCES += test_convert.cpp \
    ../convert.cpp

HEADERS += \
    ../convert.h \
    test_convert.h \
    test_convert.h

win32 {
    DEFINES += "_WIN32_WINNT=0x0600"
    DEFINES += "WINVER=0x0600"
}

INCLUDEPATH += C:\gstreamer\1.0\x86_64\include\Qt5GStreamer
INCLUDEPATH += C:\gstreamer\1.0\x86_64\include\gstreamer-1.0
INCLUDEPATH += C:\gstreamer\1.0\x86_64\include\glib-2.0
INCLUDEPATH += C:\gstreamer\1.0\x86_64\include
INCLUDEPATH += $$PWD

LIBS += -LC:\gstreamer\1.0\x86_64\lib -LC:\gstreamer\1.0\x86_64\bin -lQt5GStreamer-1.0 -lQt5GStreamerUtils-1.0 -lQt5GLib-2.0 -lgstreamer-1.0 -lglib-2.0 -lz
