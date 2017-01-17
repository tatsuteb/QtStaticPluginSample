#ifndef IPENTOOL_H
#define IPENTOOL_H

#include <QtPlugin>
#include "ITool.h"

class QPainter;

class IPenTool : virtual public ITool
{
	public:
		virtual ~IPenTool() {}

//		virtual QString getPluginName() const = 0;

//		virtual void mousePress(QPainter &painter, const QPoint &pos) = 0;
//		virtual void mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) = 0;
//		virtual void mouseRelease(QPainter &painter, const QPoint &pos) = 0;
};

#define IPenTool_iid "jp.co.tatsuteb.SimplePaint.IPenTool.v1"
Q_DECLARE_INTERFACE(IPenTool, IPenTool_iid)

#endif // IPENTOOL_H
