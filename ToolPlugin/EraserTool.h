#ifndef ERASERTOOL_H
#define ERASERTOOL_H

#include <QObject>
#include "IBasicTool.h"

class EraserTool : public QObject, public IBasicTool
{
		Q_OBJECT

	public:
		EraserTool();

		// IBasicTool interface
	public:
		QString toolName() const Q_DECL_OVERRIDE;
		void toolPress(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
		void toolMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) Q_DECL_OVERRIDE;
		void toolRelease(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;

};

#endif // ERASERTOOL_H
