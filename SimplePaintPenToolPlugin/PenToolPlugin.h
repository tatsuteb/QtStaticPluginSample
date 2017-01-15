#ifndef SIMPLEPAINTPENTOOLPLUGIN_H
#define SIMPLEPAINTPENTOOLPLUGIN_H

#include <ITool.h>

#include <QObject>
#include <QtPlugin>

class PenToolPlugin : public QObject, public ITool
{
		Q_OBJECT
		Q_PLUGIN_METADATA(IID "jp.co.tatsuteb.SimplePaint.ITool.v1" FILE "PenTool.json")
		Q_INTERFACES(ITool)

	public:
		PenToolPlugin();

		// ITool interface
	public:
		QString getPluginName() const Q_DECL_OVERRIDE;

		void mousePress(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
		void mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) Q_DECL_OVERRIDE;
		void mouseRelease(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
};

#endif // SIMPLEPAINTPENTOOLPLUGIN_H
