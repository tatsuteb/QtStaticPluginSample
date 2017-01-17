#include "EraserToolPlugin.h"

#include <QPainter>

EraserToolPlugin::EraserToolPlugin()
{
}

QString EraserToolPlugin::getPluginName() const
{
	return "EraserTool";
}

void EraserToolPlugin::mousePress(QPainter &painter, const QPoint &pos)
{

}

void EraserToolPlugin::mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::white), 5));

	painter.drawLine(oldPos, newPos);

	painter.restore();
}

void EraserToolPlugin::mouseRelease(QPainter &painter, const QPoint &pos)
{

}
