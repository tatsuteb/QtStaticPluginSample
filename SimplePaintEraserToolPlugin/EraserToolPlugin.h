#ifndef ERASERTOOLPLUGIN_H
#define ERASERTOOLPLUGIN_H

#include "IEraserTool.h"

#include <QObject>
#include <QtPlugin>

class EraserToolPlugin : public QObject, public IEraserTool
{
		Q_OBJECT
		Q_PLUGIN_METADATA(IID "jp.co.tatsuteb.SimplePaint.IEraserTool.v1" FILE "EraserTool.json")
		Q_INTERFACES(IEraserTool)

	public:
		EraserToolPlugin();

		// ITool interface
	public:
		QString getPluginName() const Q_DECL_OVERRIDE;

		void mousePress(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
		void mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) Q_DECL_OVERRIDE;
		void mouseRelease(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
};

#endif // ERASERTOOLPLUGIN_H
