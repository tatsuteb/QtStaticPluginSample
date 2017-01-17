#-------------------------------------------------
#
# Project created by QtCreator 2017-01-16T23:37:51
#
#-------------------------------------------------

QT       += widgets

QT       -= core gui

TARGET = $$qtLibraryTarget(sp_erasertool)
TEMPLATE = lib
CONFIG += plugin static

INCLUDEPATH += $$PWD/../SimplePaint/

SOURCES += EraserToolPlugin.cpp

HEADERS += EraserToolPlugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = ../SimplePaint/plugins

DISTFILES += \
    EraserTool.json
