#ifndef SIMPLEPAINT_H
#define SIMPLEPAINT_H

#include <QMainWindow>

namespace Ui {
	class SimplePaint;
}

class ITool;

class SimplePaint : public QMainWindow
{
		Q_OBJECT

	public:
		explicit SimplePaint(QWidget *parent = 0);
		~SimplePaint();

	private:
		QList<ITool *> loadToolPlugins();
		void setUpToolButtons(QList<ITool *> &tools);

	private:
		Ui::SimplePaint *ui;

	private slots:
		void changeTool();
};

#endif // SIMPLEPAINT_H
