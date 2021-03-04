#pragma once

#include <QtWidgets/QMainWindow>

#include <QGridLayout>
#include <QDebug>
#include <qsplitter.h>
#include <qdatetime.h>
#include <qprogressbar.h>
#include <qfiledialog.h>
#include <qfile.h>
#include <qstring.h>

#include "ui_QtMyShow.h"
#include "ImageWidget.h"
#include "common.h"


class QtMyShow : public QMainWindow
{
	Q_OBJECT

public:
	// ������, ��������Ҫ��Ԫ��
	// ���Ĵ����Ǳ�Ҫ��, ��Ϊ������һ��Layout���������Ҫ�Ĳ���, Ʃ��Splitter, ������Ҫ�����
	// Widget, �����Ĵ��ڿ����ṩһ�µ��ⲿ����.
	class LayoutFoo {
	public:
		LayoutFoo() {}
		virtual ~LayoutFoo() {}
		///
		/// \brief doLayout
		/// \param pxy    parent widget of xy
		/// \param sxy    slicer of xy
		/// \param pyz
		/// \param syz
		/// \param pxz
		/// \param pxz
		/// \param p3d
		/// \param bar    progress bar.
		///
		virtual void doLayout(QWidget *pxy, QWidget *pyz, QWidget *pxz,
			QWidget *p3d) = 0;
	};
	enum LayoutType { // ��������
		eLayout_Notused, // �������ڳ�ʼ��, �û����Ժ�����.
		/// <pre>
		/// |````````|````````|
		/// |  xy    |   yz   |
		/// |--------|--------|
		/// |  xz    |   3d   |
		/// |________|________|
		/// </pre>
		eLayout1
	};

	QtMyShow(QWidget *parent = Q_NULLPTR);
	~QtMyShow();

	void DoSetLayout(LayoutType lt, int timeout = 0);
	bool IsViewMaximized(SlicePane p);
	void DoRelayout();
	void MaximizeView(SlicePane p);

private:
	void open();
	void close();

	void addMyToolBar();
	QGridLayout *   addLayout(QWidget * widget, QWidget * parent);
	void setActionState();

	ImageWidget *GetImageWidget(SlicePane p) const
	{
		ImageWidget *ret = 0;
		switch (p){
		case eXY:
			ret = mXWidget;
			break;
		case eYZ:
			ret = mYWidget;
			break;
		case eXZ:
			ret = mZWidget;
			break;
		case e3D:
			ret = m3dWidget;
			break;
		default:
			break;
		}
		return ret;
	}
signals:
	void viewRestored();
	void viewMaximized(ImageWidget *w);

private:
	Ui::QtMyShowClass ui;

	//��ǰ��������
	LayoutType mLayoutType;
	LayoutFoo *mLayoutFoo;

private:

	QAction *openAction;
	QAction *exitAction;

	QWidget *mTop;
	QWidget *mXyParent, *mYzParent, *mXzParent, *m3dParent;
	ImageWidget *mXWidget, *mYWidget, *mZWidget, *m3dWidget;


};
