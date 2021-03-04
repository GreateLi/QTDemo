#include "ToolBarSlice.h"

 
#include "global.h"
#include "QtMyShow.h"
//
#include <QDial>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QToolButton>
#include <QComboBox>
#include <QDebug>
#include <qcombobox.h>

ToolBarSlice::ToolBarSlice(ImageWidget *widget)
	:ToolBar(widget)
	, mWidget(widget)
{
	mPrev = new QToolButton(this);
	mPrev->setIcon(QIcon(":/Resources/icons/prev.png"));
	mPrev->setAutoRaise(true);
	mPrev->setAutoRepeat(true);
	mNext = new QToolButton(this);
	mNext->setIcon(QIcon(":/Resources/icons/next.png"));
	mNext->setAutoRaise(true);
	mNext->setAutoRepeat(true);
	mCurr = new QLineEdit(this);
	mCurr->setFixedWidth(30);
	mCurr->setAlignment(Qt::AlignHCenter);
	mTotal = new QLineEdit(this);
	mTotal->setReadOnly(true);
	mTotal->setAlignment(Qt::AlignHCenter);
	mTotal->setFixedWidth(30);
	mTotal->setDisabled(true);
	/*mLeftButton = new QComboBox(this);
	mLeftButton->addItem(tr("W/L"));
	mLeftButton->addItem(tr("Point"));
	mLeftButton->addItem(tr("Overlay"));*/
	mPoint = new QToolButton(this);

	mLine = new QToolButton(this);
	mPointer = new QToolButton(this);
	mPointer->setCheckable(true);
	mPointer->setAutoExclusive(true);
	mOverlay = new QToolButton(this);
	mOverlay->setCheckable(true);
	mOverlay->setAutoExclusive(true);
	mClear = new QToolButton(this);

	mSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	QToolButton* maxbtn = new QToolButton(this);
	maxbtn->setAutoRaise(true);
	maxbtn->setIcon(QIcon(widget->isMaximized() ? ":/Resources/icons/icon-restore-normal.png" : ":/Resources/icons/icon-maximize-normal.png"));
	connect(maxbtn, &QToolButton::clicked, [=](bool checked) {
		Q_UNUSED(checked);
		if (widget->IsViewMaximized()) widget->RestoreView(); else widget->MaximizeView();
	});
	if (widget->GetView()) {
		connect(widget->GetView(), &QtMyShow::viewMaximized, [=](ImageWidget* w) {
			if (w->GetPane() == widget->GetPane()) {
				// it's me
				maxbtn->setIcon(QIcon(":/Resources/icons/icon-restore-normal.png"));
			}
		});
		connect(widget->GetView(), &QtMyShow::viewRestored, [=]() {
			// whatever, it's all right anyway.
			maxbtn->setIcon(QIcon(":/Resources/icons/icon-maximize-normal.png"));
		});
	}
	// layout.
	QHBoxLayout* lt = new QHBoxLayout(this);
	lt->setMargin(1);
	//lt->addWidget(mLeftButton);
	lt->addWidget(mPoint);
	lt->addWidget(mLine);
	lt->addWidget(mPointer);
	lt->addWidget(mOverlay);
	lt->addWidget(mClear);
	lt->addWidget(mPrev);
	lt->addWidget(mCurr);
	lt->addWidget(new QLabel("/", this));
	lt->addWidget(mTotal);
	lt->addWidget(mNext);
	lt->addItem(mSpacer);
	lt->addWidget(maxbtn);
	// connect
	connect(mPoint, SIGNAL(pressed()), this, SLOT(onPoint()));
	connect(mLine, SIGNAL(pressed()), this, SLOT(onLine()));
	//
	connect(mCurr, SIGNAL(textEdited(QString)), this, SLOT(changeSlice(QString)), Qt::UniqueConnection);
	connect(mPrev, SIGNAL(released()), this, SLOT(changeToPrev()));
	connect(mNext, SIGNAL(released()), this, SLOT(changeToNext()));
	//connect(mLeftButton, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentIndexChanged(int)), Qt::UniqueConnection);
	connect(mPointer, SIGNAL(toggled(bool)), this, SLOT(onPointer(bool)));
	connect(mOverlay, SIGNAL(toggled(bool)), this, SLOT(onOverlay(bool)));
	connect(mClear, SIGNAL(pressed()), this, SLOT(onClear()));
	//
	Refresh();
}

void ToolBarSlice::enableSliceThings(bool b)
{
	mCurr->setEnabled(b);
	mTotal->setEnabled(b);
	mPrev->setEnabled(b);
	mNext->setEnabled(b);
}

void ToolBarSlice::Refresh()
{
	if (Global::Instance()->GetMajor().isEmpty()){
		enableSliceThings(false);
	}
	else{

	}

}

void ToolBarSlice::changeToPrev()
{
	int curr = mCurr->text().toInt();
	if (curr > 1){
		changeSlice(curr - 1);
	}
}

void ToolBarSlice::changeToNext()
{
	int curr = mCurr->text().toInt();
	int total = mTotal->text().toInt();
	if (curr < total){
		changeSlice(curr + 1);
	}
}

void ToolBarSlice::changeSlice(int slice)
{

}

void ToolBarSlice::changeSlice(const QString &text)
{
	int slice = text.toInt();
	changeSlice(slice);
}

void ToolBarSlice::onCurrentIndexChanged(int index)
{

}

void ToolBarSlice::onPointer(bool b)
{

}

void ToolBarSlice::onOverlay(bool b)
{

}

void ToolBarSlice::onClear()
{

}

void ToolBarSlice::onPoint()
{

}

void ToolBarSlice::onLine()
{
	
}
