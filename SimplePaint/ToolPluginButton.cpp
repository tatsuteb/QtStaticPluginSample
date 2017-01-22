#include "ITool.h"
#include "ToolPluginButton.h"

ToolPluginButton::ToolPluginButton(ITool *tool, QWidget *parent) : QPushButton(parent),
	m_tool(tool)
{
	setText(m_tool->getPluginName());
}

ITool *ToolPluginButton::getTool() const
{
	return m_tool;
}
