#ifndef TOOLPLUGIN_H
#define TOOLPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "ITool.h"

class IBasicTool;
class PenTool;
class EraserTool;

class ToolPlugin : public QObject, public ITool
{
		Q_OBJECT
		Q_PLUGIN_METADATA(IID "jp.co.tatsuteb.SimplePaint.ITool.v1" FILE "ToolPlugin.json")
		Q_INTERFACES(ITool)

	public:
		ToolPlugin();

		// ITool interface
	public:
		QStringList getToolNames() const Q_DECL_OVERRIDE;
		void setCurrentTool(const QString &toolName) Q_DECL_OVERRIDE;
		void mousePress(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
		void mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) Q_DECL_OVERRIDE;
		void mouseRelease(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;

	private:
		QList<IBasicTool *> m_tools;
		PenTool *m_penTool;
		EraserTool *m_eraserTool;
		int m_currentToolIndex;

};

#endif // TOOLPLUGIN_H
