#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>

namespace Ui {
	class CanvasWidget;
}

class ITool;

class CanvasWidget : public QWidget
{
		Q_OBJECT

	public:
		explicit CanvasWidget(QWidget *parent = 0);
		~CanvasWidget();

		void setCurrentTool(ITool *tool);
		void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

	protected:
		void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
		void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
		void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

	private:
		const static QColor BACKGROUND_COLOR;
		const static QSize INITIAL_IMAGE_SIZE;

	private:
		Ui::CanvasWidget *ui;

		ITool *m_tool;
		QImage m_canvasImage;
		QPoint m_lastPos;
};

#endif // CANVASWIDGET_H
