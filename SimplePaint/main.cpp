#include "SimplePaint.h"
#include <QApplication>

#include <QtPlugin>

//Q_IMPORT_PLUGIN(PenToolPlugin)
//Q_IMPORT_PLUGIN(EraserToolPlugin)
Q_IMPORT_PLUGIN(ToolPlugin)

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SimplePaint w;
	w.show();

	return a.exec();
}
