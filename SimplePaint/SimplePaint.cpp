#include "SimplePaint.h"
#include "ui_SimplePaint.h"

#include <QDebug>
#include <QPluginLoader>
#include <QPushButton>

#include "ITool.h"
#include "ToolPluginButton.h"

SimplePaint::SimplePaint(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::SimplePaint)
{
	ui->setupUi(this);

	loadPlugins();

	for (auto tool : m_tools)
	{
		qDebug() << tool->getPluginName();
	}

}

SimplePaint::~SimplePaint()
{
	delete ui;
}

void SimplePaint::loadPlugins()
{
	for (QObject *plugin : QPluginLoader::staticInstances())
	{
		m_tools << qobject_cast<ITool *>(plugin);
	}

	QButtonGroup *toolButtonGroup = new QButtonGroup();
	QVBoxLayout *vLayout = new QVBoxLayout();
	for (auto tool : m_tools)
	{
		ToolPluginButton *pushButton_tool = new ToolPluginButton(tool);
		pushButton_tool->setCheckable(true);
		connect(pushButton_tool, &ToolPluginButton::clicked, this, &SimplePaint::changeTool);

		toolButtonGroup->addButton(pushButton_tool);

		vLayout->addWidget(pushButton_tool);
	}
	ui->frame_tools->setLayout(vLayout);

}

void SimplePaint::changeTool()
{
	auto button = qobject_cast<ToolPluginButton *>(sender());

	ui->widget_canvas->setCurrentTool(button->getTool());
}
