#include "EraserToolPlugin.h"

#include <QPainter>


EraserToolPlugin::EraserToolPlugin():
	m_eraserSize(20)
{
}

QString EraserToolPlugin::getPluginName() const
{
	return "EraserTool";
}

void EraserToolPlugin::mousePress(QPainter &painter, const QPoint &pos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::GlobalColor::white), m_eraserSize));

	painter.drawPoint(pos);

	painter.restore();
}

void EraserToolPlugin::mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::GlobalColor::white), m_eraserSize));

	painter.drawLine(oldPos, newPos);

	painter.restore();
}

void EraserToolPlugin::mouseRelease(QPainter &painter, const QPoint &pos)
{
}
