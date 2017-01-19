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
		bool loadPlugins();
		void addTools(const ITool &m_tools);

	private:
		Ui::SimplePaint *ui;

		ITool *m_tools;

	private slots:
		void changeTool();
};

#endif // SIMPLEPAINT_H
