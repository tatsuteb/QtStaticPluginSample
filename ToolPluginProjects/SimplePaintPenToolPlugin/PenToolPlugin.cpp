#include "PenToolPlugin.h"

#include <QPainter>


PenToolPlugin::PenToolPlugin():
	m_penSize(1)
{
}

QString PenToolPlugin::getPluginName() const
{
	return "PenTool";
}

void PenToolPlugin::mousePress(QPainter &painter, const QPoint &pos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::GlobalColor::black), m_penSize));

	painter.drawPoint(pos);

	painter.restore();
}

void PenToolPlugin::mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::GlobalColor::black), m_penSize));

	painter.drawLine(oldPos, newPos);

	painter.restore();
}

void PenToolPlugin::mouseRelease(QPainter &painter, const QPoint &pos)
{
}
