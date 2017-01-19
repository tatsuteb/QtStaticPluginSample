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
#    IPenTool.h \
#    IEraserTool.h

FORMS    += SimplePaint.ui \
    CanvasWidget.ui

LIBS    += -L$$PWD/plugins/ -lsp_toolplugin
#LIBS    += -L$$PWD/plugins/ -lsp_pentool
#LIBS    += -L$$PWD/plugins/ -lsp_erasertool

# デバッグビルドは_debugで終わるプラグインをロード
if(!debug_and_release|build_pass):CONFIG(debug, debug|release) {
   mac:LIBS = $$member(LIBS, 0) $$member(LIBS, 1)_debug
   win32:LIBS = $$member(LIBS, 0) $$member(LIBS, 1)d
}
