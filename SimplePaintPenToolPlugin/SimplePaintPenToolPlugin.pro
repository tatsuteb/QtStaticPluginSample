#-------------------------------------------------
#
# Project created by QtCreator 2017-01-15T17:44:03
#
#-------------------------------------------------

QT       += widgets

QT       -= core gui

TARGET = $$qtLibraryTarget(sp_pentool)
TEMPLATE = lib
CONFIG += plugin static

INCLUDEPATH += $$PWD/../SimplePaint/

SOURCES += \
    PenToolPlugin.cpp

HEADERS += \
    PenToolPlugin.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DESTDIR = ../SimplePaint/plugins

DISTFILES += \
    PenTool.json


