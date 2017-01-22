#ifndef TOOLPLUGINBUTTON_H
#define TOOLPLUGINBUTTON_H

#include <QPushButton>

class ITool;

class ToolPluginButton : public QPushButton
{
		Q_OBJECT
	public:
		explicit ToolPluginButton(ITool *tool, QWidget *parent = 0);

		ITool *getTool() const;

	private:
		ITool *m_tool;
};

#endif // TOOLPLUGINBUTTON_H
