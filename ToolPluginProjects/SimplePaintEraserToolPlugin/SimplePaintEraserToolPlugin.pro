#-------------------------------------------------
#
# Project created by QtCreator 2017-01-22T12:21:34
#
#-------------------------------------------------

QT  += core

# 出力するプラグイン名を指定する
# $$qtLibraryTargetは、デバッグビルド時にmacの場合は_debugを、windowsの場合は_dをプラグイン名の後ろにつけてくれる
TARGET = $$qtLibraryTarget(sp_erasertool)
TEMPLATE = lib
# スタティックプラグインとしてビルドしたいので、pluginとstaticを指定
CONFIG += plugin static

# このプラグインのインターフェースを定義した.hファイルがあるディレクトリを指定
INCLUDEPATH += $$PWD/../../SimplePaint/

SOURCES += EraserToolPlugin.cpp

HEADERS += EraserToolPlugin.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

# このプラグインを保存する場所を指定
DESTDIR = $$PWD/../../SimplePaint/plugins

# このプラグインのメタデータファイル
DISTFILES += \
    EraserTool.json
