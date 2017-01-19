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

	if (loadPlugins())
	{
		addTools(*m_tools);
		ui->widget_canvas->setTools(*m_tools);
	}
}

SimplePaint::~SimplePaint()
{
	delete ui;
}

bool SimplePaint::loadPlugins()
{
	for (QObject *plugin : QPluginLoader::staticInstances())
	{
		// キャストに失敗したら0が返る
		m_tools = qobject_cast<ITool *>(plugin);

		// ロードしたプラグインがIToolだったらループを抜ける
		if (m_tools != 0)
		{
			return true;
		}
	}

	return false;
}

void SimplePaint::addTools(const ITool &m_tools)
{
	QButtonGroup *toolButtonGroup = new QButtonGroup();
	QVBoxLayout *vLayout = new QVBoxLayout();

	QStringList toolNames = m_tools.getToolNames();
	for (const auto &name : toolNames)
	{
		ToolPluginButton *pushButton_tool = new ToolPluginButton(name);
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

	m_tools->setCurrentTool(button->toolName());
}
