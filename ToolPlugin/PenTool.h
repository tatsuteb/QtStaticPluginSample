#ifndef PENTOOL_H
#define PENTOOL_H

#include <QObject>
#include "IBasicTool.h"

class PenTool : public QObject, public IBasicTool
{
		Q_OBJECT

	public:
		PenTool();

		// IBasicTool interface
	public:
		QString toolName() const Q_DECL_OVERRIDE;
		void toolPress(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
		void toolMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) Q_DECL_OVERRIDE;
		void toolRelease(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;

};

#endif // PENTOOL_H
