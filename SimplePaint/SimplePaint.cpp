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

	QList<ITool *> loadedTools = loadToolPlugins();
	setUpToolButtons(loadedTools);
}

SimplePaint::~SimplePaint()
{
	delete ui;
}

QList<ITool *> SimplePaint::loadToolPlugins()
{
	QList<ITool *> tools;
	for (QObject *plugin : QPluginLoader::staticInstances())
	{
		// qobject_castはキャストに失敗すると0を返す
		auto tool = qobject_cast<ITool *>(plugin);

		// ITool以外のプラグインは無視
		if (!tool)
		{
			continue;
		}

		tools << tool;
	}

	return tools;
}

void SimplePaint::setUpToolButtons(QList<ITool *> &tools)
{
	if (tools.isEmpty())
	{
		return;
	}

	QButtonGroup *toolButtonGroup = new QButtonGroup();
	QVBoxLayout *vLayout = new QVBoxLayout();
	for (auto tool : tools)
	{
		ToolPluginButton *pushButton_tool = new ToolPluginButton(tool);
		pushButton_tool->setCheckable(true);
		connect(pushButton_tool, &ToolPluginButton::clicked, this, &SimplePaint::changeTool);

		toolButtonGroup->addButton(pushButton_tool);
		vLayout->addWidget(pushButton_tool);
	}
	vLayout->addStretch();

	ui->frame_tools->setLayout(vLayout);
}

void SimplePaint::changeTool()
{
	auto button = qobject_cast<ToolPluginButton *>(sender());

	ui->widget_canvas->setCurrentTool(button->getTool());
}
