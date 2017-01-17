#ifndef IERASERTOOL_H
#define IERASERTOOL_H

#include <QtPlugin>
#include "ITool.h"

class IEraserTool : virtual public ITool
{
	public:
		virtual ~IEraserTool() {}
};

#define IEraserTool_iid "jp.co.tatsuteb.SimplePaint.IEraserTool.v1"
Q_DECLARE_INTERFACE(IEraserTool, IEraserTool_iid)


#endif // IERASERTOOL_H
