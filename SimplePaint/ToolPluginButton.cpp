#include "ITool.h"
#include "ToolPluginButton.h"

ToolPluginButton::ToolPluginButton(const QString &toolName, QWidget *parent) : QPushButton(parent),
	m_toolName(toolName)
{
	setText(toolName);
}

const QString &ToolPluginButton::toolName() const
{
	return m_toolName;
}
