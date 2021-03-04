#pragma once

#include <QObject>
#include "ImageWidget.h"
//
#include <qwidget.h>

class ImageWidget;
class ToolBar : public QWidget
{
	Q_OBJECT
public:
	explicit ToolBar(ImageWidget *widget);
	~ToolBar();

	virtual void Refresh(){}

	ImageWidget *GetImageWidget(){ return mWidget; }

protected:
	ImageWidget *mWidget;
};
