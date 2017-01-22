#-------------------------------------------------
#
# Project created by QtCreator 2017-01-15T16:46:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimplePaint
TEMPLATE = app

SOURCES += main.cpp\
        SimplePaint.cpp \
    CanvasWidget.cpp \
    ToolPluginButton.cpp

HEADERS  += SimplePaint.h \
    CanvasWidget.h \
    ITool.h \
    ToolPluginButton.h

FORMS    += SimplePaint.ui \
    CanvasWidget.ui

# プラグインを検索するディレクトリと、プラグインの名前を指定
# -L : 検索するディレクトリ
# -l : ライブラリ名
LIBS    += -L$$PWD/plugins/ -lsp_pentool -lsp_erasertool

# デバッグビルドは_debugで終わるプラグインをロード
# LIBSにプラグインを追加したら、$$memberも忘れずに追加すること
# $$member(LIBS, 0) は LIBSの0番目の値を取得する、という意味になる
if(!debug_and_release|build_pass):CONFIG(debug, debug|release) {
   mac:LIBS = $$member(LIBS, 0) $$member(LIBS, 1)_debug $$member(LIBS, 2)_debug
   win32:LIBS = $$member(LIBS, 0) $$member(LIBS, 1)d $$member(LIBS, 2)d
}
