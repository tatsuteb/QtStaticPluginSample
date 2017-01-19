#include <QDebug>
#include <QPainter>

#include "PenTool.h"

PenTool::PenTool() : QObject()
{

}

QString PenTool::toolName() const
{
	return "Pen Tool";
}

void PenTool::toolPress(QPainter &painter, const QPoint &pos)
{
	qDebug() << "tool press";
}

void PenTool::toolMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::black), 1));

	painter.drawLine(oldPos, newPos);

	painter.restore();
}

void PenTool::toolRelease(QPainter &painter, const QPoint &pos)
{
	qDebug() << "tool release";
}
