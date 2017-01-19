#ifndef TOOLPLUGINBUTTON_H
#define TOOLPLUGINBUTTON_H

#include <QPushButton>

class ITool;

class ToolPluginButton : public QPushButton
{
		Q_OBJECT
	public:
		explicit ToolPluginButton(const QString &toolName, QWidget *parent = 0);

		const QString &toolName() const;

	private:
		QString m_toolName;

	signals:

	public slots:
};

#endif // TOOLPLUGINBUTTON_H
