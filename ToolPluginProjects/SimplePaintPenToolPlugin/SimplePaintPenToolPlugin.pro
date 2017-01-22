#-------------------------------------------------
#
# Project created by QtCreator 2017-01-15T17:44:03
#
#-------------------------------------------------

QT  += core

# 出力するプラグイン名を指定する
# $$qtLibraryTargetは、デバッグビルド時にmacの場合は_debugを、windowsの場合は_dをプラグイン名の後ろにつけてくれる
TARGET = $$qtLibraryTarget(sp_pentool)
TEMPLATE = lib
# スタティックプラグインとしてビルドしたいので、pluginとstaticを指定
CONFIG += plugin static

# このプラグインのインターフェースを定義した.hファイルがあるディレクトリを指定
INCLUDEPATH += $$PWD/../../SimplePaint/

SOURCES += \
    PenToolPlugin.cpp

HEADERS += \
    PenToolPlugin.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

# このプラグインを保存する場所を指定
DESTDIR = $$PWD/../../SimplePaint/plugins

# このプラグインのメタデータファイル
DISTFILES += \
    PenTool.json


