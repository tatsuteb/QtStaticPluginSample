#ifndef ITOOL_H
#define ITOOL_H

#include <QtPlugin>

class QPainter;
class QPoint;
class QString;

class ITool
{
	public:
		virtual ~ITool() {}

		virtual QStringList getToolNames() const = 0;
		virtual void setCurrentTool(const QString &toolName) = 0;

		virtual void mousePress(QPainter &painter, const QPoint &pos) = 0;
		virtual void mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) = 0;
		virtual void mouseRelease(QPainter &painter, const QPoint &pos) = 0;
};

#define ITool_iid "jp.co.tatsuteb.SimplePaint.ITool.v1"
Q_DECLARE_INTERFACE(ITool, ITool_iid)

#endif // ITOOL_H
