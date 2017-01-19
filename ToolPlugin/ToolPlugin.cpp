#include "ToolPlugin.h"

#include "IBasicTool.h"
#include "PenTool.h"
#include "EraserTool.h"

ToolPlugin::ToolPlugin() : QObject(),
	m_penTool(new PenTool),
	m_eraserTool(new EraserTool),
	m_currentToolIndex(0)
{
	m_tools << m_penTool << m_eraserTool;
}

QStringList ToolPlugin::getToolNames() const
{
	QStringList toolName;

	for (auto tool : m_tools)
	{
		toolName << tool->toolName();
	}

	return toolName;
}

void ToolPlugin::setCurrentTool(const QString &toolName)
{
	for (int i = 0; i < m_tools.count(); i++)
	{
		if (m_tools[i]->toolName() != toolName)
		{
			continue;
		}

		m_currentToolIndex = i;
		break;
	}
}

void ToolPlugin::mousePress(QPainter &painter, const QPoint &pos)
{
	m_tools[m_currentToolIndex]->toolPress(painter, pos);
}

void ToolPlugin::mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos)
{
	m_tools[m_currentToolIndex]->toolMove(painter, oldPos, newPos);
}

void ToolPlugin::mouseRelease(QPainter &painter, const QPoint &pos)
{
	m_tools[m_currentToolIndex]->toolRelease(painter, pos);
}
