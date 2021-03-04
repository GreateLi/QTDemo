#include "ToolBar.h"

 
ToolBar::ToolBar(ImageWidget *widget)
	:QWidget(widget)
	, mWidget(widget)
{
	setMaximumHeight(35);
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
}

ToolBar::~ToolBar()
{
}
