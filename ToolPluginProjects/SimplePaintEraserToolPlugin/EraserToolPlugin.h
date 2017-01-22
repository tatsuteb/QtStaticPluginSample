#ifndef ERASERTOOLPLUGIN_H
#define ERASERTOOLPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "ITool.h"

class EraserToolPlugin : public QObject, public ITool
{
		Q_OBJECT

		// このプラグインをエクスポートできるようにする。Q_OBJECTマクロの後に記述
		// このプラグインを受け入れる本体側で書いたIIDと合わせる。jsonファイルは、プラグインのメタデータ
		Q_PLUGIN_METADATA(IID "jp.tatsuteb.SimplePaint.ITool.v1" FILE "EraserTool.json")

		// mocに、基底クラスはプラグインインターフェースであることを伝える。このマクロによりqobject_cast()が使えるようになる
		Q_INTERFACES(ITool)

	public:
		EraserToolPlugin();

		// ITool interface
	public:
		QString getPluginName() const Q_DECL_OVERRIDE;
		void mousePress(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;
		void mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) Q_DECL_OVERRIDE;
		void mouseRelease(QPainter &painter, const QPoint &pos) Q_DECL_OVERRIDE;

	private:
		int m_eraserSize;
};

#endif // ERASERTOOLPLUGIN_H
