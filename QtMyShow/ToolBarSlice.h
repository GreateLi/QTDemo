#pragma once

#include "ToolBar.h"

 
	class QSlider;
	class QLineEdit;
	class QIntValidator;
	class QToolButton;
	class QComboBox;
	class QSpacerItem;

	class ToolBarSlice :public ToolBar
	{
		Q_OBJECT
	public:
		explicit ToolBarSlice(ImageWidget *widget);

		void Refresh();

		protected slots:
		/*!
		* \brief changeSlice
		* \param slice, 1,2,3,...
		*/
		void changeSlice(int slice);
		/*!
		* \brief changeSlice
		* \param text, such as 1, 2, 3, 4, .etc
		*/
		void changeSlice(const QString& text);
		//
		void changeToPrev();
		void changeToNext();
		//
		void onPointer(bool);
		void onOverlay(bool);
		void onClear();
		//
		void onPoint();
		void onLine();
		//
		void onCurrentIndexChanged(int);
	protected:
		// QT/slice
		//QComboBox* mLeftButton;
		QToolButton* mPoint;
		QToolButton* mLine;
		QToolButton* mPointer;
		QToolButton* mOverlay;
		QToolButton* mClear;
		QLineEdit* mCurr;
		QLineEdit* mTotal;
		QToolButton* mPrev;
		QToolButton* mNext;
		QSpacerItem* mSpacer;
		//
		ImageWidget* mWidget;
		//
		void enableSliceThings(bool b);
	};

 
