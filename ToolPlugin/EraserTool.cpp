#include <QDebug>
#include <QPainter>

#include "EraserTool.h"

EraserTool::EraserTool()
{

}

QString EraserTool::toolName() const
{
	return "Eraser Tool";
}

void EraserTool::toolPress(QPainter &painter, const QPoint &pos)
{
	qDebug() << "tool press";
}

void EraserTool::toolMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos)
{
	painter.save();

	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QBrush(Qt::white), 10));

	painter.drawLine(oldPos, newPos);

	painter.restore();
}

void EraserTool::toolRelease(QPainter &painter, const QPoint &pos)
{
	qDebug() << "tool release";
}
