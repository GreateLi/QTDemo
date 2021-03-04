#pragma once

#include <QWidget>
#include "ui_ImageWidget.h"
#include "common.h"
#include "ToolBar.h"

class QtMyShow;
class ToolBar;


namespace Ui{
	class ImageWidget;
}


class ImageWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ImageWidget(QtMyShow *view, SlicePane pane, QWidget* parent = Q_NULLPTR);
	~ImageWidget();

private:
	Ui::ImageWidget ui;
	QtMyShow *mView;
 
 
	ToolBar *mToolBar;
	int mPane;
public :

	bool IsViewMaximized()const;
	void RestoreView();
	void MaximizeView();
	//
	QtMyShow *GetView() const;
	//
	int GetPane() const { return mPane; }
};
