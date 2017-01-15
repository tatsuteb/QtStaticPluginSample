#include "CanvasWidget.h"
#include "ITool.h"
#include "ui_CanvasWidget.h"

#include <QMouseEvent>
#include <QPainter>

CanvasWidget::CanvasWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CanvasWidget),
	m_lastPos(QPoint(0, 0))/*,
	canvasImage(QImage(this->size(), QImage::Format_RGB32))*/
{
	ui->setupUi(this);

	m_canvasImage = QImage(this->size(), QImage::Format_RGB32);
	m_canvasImage.fill(Qt::white);
}

CanvasWidget::~CanvasWidget()
{
	delete ui;
}

void CanvasWidget::setCurrentTool(ITool *tool)
{
	m_tool = tool;
}

void CanvasWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.drawImage(QPoint(0, 0), m_canvasImage);
}

QSize CanvasWidget::sizeHint() const
{
	return m_canvasImage.size();
}

void CanvasWidget::mousePressEvent(QMouseEvent *e)
{
	if (m_tool == nullptr) return;

	QPainter painter(&m_canvasImage);
	m_tool->mousePress(painter, e->pos());

	update();

	m_lastPos = e->pos();
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (m_tool == nullptr) return;

	QPainter painter(&m_canvasImage);
	m_tool->mouseRelease(painter, e->pos());

	update();

	m_lastPos = e->pos();
}

void CanvasWidget::mouseMoveEvent(QMouseEvent *e)
{
	if (m_tool == nullptr) return;

	QPainter painter(&m_canvasImage);
	m_tool->mouseMove(painter, m_lastPos, e->pos());

	update();

	m_lastPos = e->pos();
}
