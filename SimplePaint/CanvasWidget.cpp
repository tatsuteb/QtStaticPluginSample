#include "CanvasWidget.h"
#include "ui_CanvasWidget.h"

#include "ITool.h"

#include <QMouseEvent>
#include <QPainter>

const QColor CanvasWidget::BACKGROUND_COLOR = Qt::white;
const QSize CanvasWidget::INITIAL_IMAGE_SIZE = QSize(100, 100);

CanvasWidget::CanvasWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CanvasWidget),
	m_tool(nullptr),
	m_canvasImage(QImage(INITIAL_IMAGE_SIZE, QImage::Format_ARGB32_Premultiplied)),
	m_lastPos(QPoint(0, 0))
{
	ui->setupUi(this);

	m_canvasImage.fill(BACKGROUND_COLOR);
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

	// キャンバスがm_canvasImageより大きいときだけ、m_canvasImageを広げる
	if (m_canvasImage.size().width() < this->size().width() ||
		m_canvasImage.size().height() < this->size().height())
	{
		QImage img(m_canvasImage.size().expandedTo(this->size()), m_canvasImage.format());
		img.fill(BACKGROUND_COLOR);

		QPainter imgPainter(&img);
		imgPainter.drawImage(QPoint(0, 0), m_canvasImage);

		m_canvasImage = img;
	}

	painter.drawImage(QPoint(0, 0), m_canvasImage);
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
