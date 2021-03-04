#include "QtMyShow.h"
#include "QTimer.h"


QtMyShow::QtMyShow(QWidget *parent)
	: QMainWindow(parent),
 
	mLayoutType(eLayout_Notused)
	, mLayoutFoo(0)
	 
{
	ui.setupUi(this);
	addMyToolBar();

	QGridLayout * gridLayout = new QGridLayout(this);

	mTop = new QWidget(this);

	gridLayout->addWidget(mTop);
	gridLayout->setMargin(0);

	mXyParent = new QWidget(mTop);
	mYzParent = new QWidget(mTop);
	mXzParent = new QWidget(mTop);
	m3dParent = new QWidget(mTop);
 
  
	mXWidget = new ImageWidget(this, eXY, mXyParent);
	mYWidget = new ImageWidget(this, eYZ, mYzParent);
	mZWidget = new ImageWidget(this, eXZ, mXzParent);
	m3dWidget = new ImageWidget(this, e3D, m3dParent);


	addLayout(mXWidget, mXyParent);
	addLayout(mYWidget, mYzParent);
	addLayout(mZWidget, mXzParent);
	addLayout(m3dWidget, m3dParent);

	//QGridLayout *mLayout = new QGridLayout(mTop);
	//mLayout->setMargin(1);
	//mLayout->setSpacing(1);

	//mLayout->addWidget(mXWidget, 0, 0);
	//mLayout->addWidget(mYWidget, 0, 1);
	//mLayout->addWidget(mZWidget, 1, 0);
	//mLayout->addWidget(m3dWidget, 1, 1);


 //  mTop->show();

    DoSetLayout(eLayout1, 0);

	ui.centralWidget->setLayout(gridLayout);
}

 

QtMyShow::~QtMyShow()
{
	 
}

namespace foo{
	// provide QGridLayout
	class LayoutBase : public QtMyShow::LayoutFoo {
	public:
		LayoutBase(QWidget *top)
			: mTop(top)
		{
			mLayout = new QGridLayout(top);
			mLayout->setMargin(1);
			mLayout->setSpacing(1);
		}
		virtual ~LayoutBase()
		{
			delete mLayout;
		}
		virtual void doLayout(QWidget *pxy, QWidget *pyz, QWidget *pxz,
			QWidget *p3d)
		{
 
		    showThem(QList<QWidget*>() << pxy << pyz << pxz << p3d);
			mLayout->addWidget(pxy, 0, 0);
			mLayout->addWidget(pyz, 0, 1);
			mLayout->addWidget(pxz, 1, 0);
			mLayout->addWidget(p3d, 1, 1);
		}
		static void showThem(const QList<QWidget*>& list)
		{
			foreach(auto p, list) {
				p->show();
			}
		}
		QGridLayout* layout() const { return mLayout; }
	protected:
		QGridLayout *mLayout;
		QWidget* mTop;
	};
}

void  QtMyShow::addMyToolBar()
{
	openAction = new QAction(QIcon(":/images/open"), tr("&Open..."), this);
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file"));
	connect(openAction, &QAction::triggered, this, &QtMyShow::open);//&MainWindow?
	//QMenu *file = menuBar()->addMenu(tr("&File"));
	//file->addAction(openAction);

	exitAction = new QAction(QIcon(":/images/close"), tr("&Exit..."), this);
	exitAction->setShortcuts(QKeySequence::Close);
	exitAction->setStatusTip(tr("exit the app"));
	connect(exitAction, &QAction::triggered, this, &QtMyShow::close);
//	file->addAction(exitAction);
	 
	QToolBar *toolBar = addToolBar(tr("&File"));
	toolBar->addAction(openAction);
	toolBar->addAction(exitAction);
}

QGridLayout * QtMyShow::addLayout(QWidget * widget, QWidget * parent)
{
	QGridLayout *layout_xy = new QGridLayout(parent);
	layout_xy->setSpacing(0);
	layout_xy->setMargin(0);
	layout_xy->addWidget(widget);

	QPalette pal(widget->palette());
	pal.setColor(QPalette::Background, Qt::gray); //设置背景
	widget->setAutoFillBackground(true);
	widget->setPalette(pal);
	// widget->show();

	return NULL;
}


void QtMyShow::open()
{

}

void QtMyShow::close()
{

}

void QtMyShow::setActionState()
{
	if (openAction->isEnabled())
	{
		openAction->setEnabled(false);
	}
	else
	{
		openAction->setEnabled(true);
	}
	
	if (exitAction->isEnabled())
	{
		exitAction->setEnabled(false);
	}
	else
	{
		exitAction->setEnabled(true);
	}
}

bool QtMyShow::IsViewMaximized(SlicePane p)
{
	QList<QWidget*> widgets;
	switch (p) {
	case eXY:
		// 把不需要看到的隐藏
		widgets = QList<QWidget*>() << mYzParent
			<< mXzParent
			<< m3dParent;
		break;
	case eYZ:
		widgets = QList<QWidget*>() << mXyParent
			<< mXzParent
			<< m3dParent;
		break;
	case eXZ:
		widgets = QList<QWidget*>() << mXyParent
			<< mYzParent
			<< m3dParent;
		break;
	case e3D:
		widgets = QList<QWidget*>() << mXyParent
			<< mYzParent
			<< mXzParent;
		break;
	default:
		break;
	}
	bool yes = GetImageWidget(p)->isVisible();
	foreach(QWidget* w, widgets) {
		yes = yes && !w->isVisible();
	}
	return yes;
}

void QtMyShow::DoRelayout()
{
	LayoutType lt = mLayoutType;
	mLayoutType = eLayout_Notused;
	DoSetLayout(lt);
}

void QtMyShow::MaximizeView(SlicePane p)
{
	QWidget* max = nullptr;
	QList<QWidget*> widgets;
	switch (p) {
	case eXY:
		// 把不需要看到的隐藏
		widgets = QList<QWidget*>() << mYzParent
			<< mXzParent
			<< m3dParent;
		max = mXyParent;
		break;
	case eYZ:
		widgets = QList<QWidget*>() << mXyParent
			<< mXzParent
			<< m3dParent;
		max = mYzParent;
		break;
	case eXZ:
		widgets = QList<QWidget*>() << mXyParent
			<< mYzParent
			<< m3dParent;
		max = mXzParent;
		break;
	case e3D:
		widgets = QList<QWidget*>() << mXyParent
			<< mYzParent
			<< mXzParent;
		max = m3dParent;
		break;
	default:return;
	}
	foreach(QWidget* w, widgets) {
		w->hide();
	}
	delete mLayoutFoo; mLayoutFoo = new foo::LayoutBase(mTop);
	static_cast<foo::LayoutBase*>(mLayoutFoo)->layout()->addWidget(max);
	max->show();
	QApplication::processEvents();
	//
	emit viewMaximized(GetImageWidget(p));
}

void QtMyShow::DoSetLayout(LayoutType lt, int timeout)
{
	// should we change layout ?
	if (mLayoutType == lt) return; // No, it's a mistake.
#if LIBHAWK_WITH_VTK < 800
	mTop->hide(); QApplication::processEvents();
#else
	Q_UNUSED(timeout);
#endif
	// delete old layout
	delete mLayoutFoo;
	switch (lt) {
	case eLayout1:
		mLayoutFoo = new foo::LayoutBase(mTop);
		break;
	default:
		abort(); // DO NOT SET layout-type which we do not support yet.
		break;
	}
	if (mLayoutFoo) {
		mLayoutFoo->doLayout(mXyParent, mYzParent, mXzParent, m3dParent);
	}
	// 记录它
	mLayoutType = lt;
#if LIBHAWK_WITH_VTK < 800
	if (timeout > 0) {
		QTimer::singleShot(timeout, this, SLOT(show()));
	}
	else {
		mTop->show();
	}
#endif
	emit viewRestored();
	QApplication::processEvents();
}