#-------------------------------------------------
#
# Project created by QtCreator 2017-01-18T23:35:18
#
#-------------------------------------------------

QT       += core gui

TARGET = $$qtLibraryTarget(sp_toolplugin)
TEMPLATE = lib
CONFIG += plugin static

INCLUDEPATH += $$PWD/../SimplePaint/

SOURCES += ToolPlugin.cpp \
    PenTool.cpp \
    EraserTool.cpp

HEADERS += ToolPlugin.h \
    IBasicTool.h \
    PenTool.h \
    EraserTool.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = ../SimplePaint/plugins

DISTFILES += \
    ToolPlugin.json
