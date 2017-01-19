#ifndef IBASICTOOL_H
#define IBASICTOOL_H

class QPoint;
class QPainter;
class QString;

class IBasicTool
{
	public:
		~IBasicTool() {}

		virtual QString toolName() const = 0;
		virtual void toolPress(QPainter &painter, const QPoint &pos) = 0;
		virtual void toolMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) = 0;
		virtual void toolRelease(QPainter &painter, const QPoint &pos) = 0;

};

#endif // IBASICTOOL_H
