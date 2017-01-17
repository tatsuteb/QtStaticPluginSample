#include "PenToolPlugin.h"

#include <QPainter>


PenToolPlugin::PenToolPlugin()
{
}

QString PenToolPlugin::getPluginName() const
{
	return "PenTool";
}

void PenToolPlugin::mousePress(QPainter &painter, const QPoint &pos)
{
}

void PenToolPlugin::mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::black), 1));

	painter.drawLine(oldPos, newPos);

	painter.restore();
}

void PenToolPlugin::mouseRelease(QPainter &painter, const QPoint &pos)
{
}
