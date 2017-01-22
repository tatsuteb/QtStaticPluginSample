#ifndef ITOOL_H
#define ITOOL_H

#include <QtPlugin>

class QPainter;
class QPoint;

class ITool
{
	public:
		virtual ~ITool() {}

		virtual QString getPluginName() const = 0;

		virtual void mousePress(QPainter &painter, const QPoint &pos) = 0;
		virtual void mouseMove(QPainter &painter, const QPoint &oldPos, const QPoint &newPos) = 0;
		virtual void mouseRelease(QPainter &painter, const QPoint &pos) = 0;
};

// ここで指定したIDと、インターフェースクラスを関連づける
// ロードしたプラグインが、このインターフェースの実装を持っているかどうか照会するのに使われる
#define ITool_iid "jp.tatsuteb.SimplePaint.ITool.v1"
Q_DECLARE_INTERFACE(ITool, ITool_iid)

#endif // ITOOL_H
