#include "ImageWidget.h"

#include <qlayout.h>
#include <qpushbutton.h>
#include <qfile.h>
#include <qpainter.h>
#include <qpen.h>
#include "ToolBarSlice.h"
#include "QtMyShow.h"

ImageWidget::ImageWidget(QtMyShow *view, SlicePane pane, QWidget *parent)
	: QWidget(parent)
	, mPane(pane)
	, mView(view)
{
	ui.setupUi(this);

	auto layout = new QVBoxLayout(this);
	layout->setMargin(1);
	layout->setSpacing(0);
	//if (pane == e3D){
	//	 
	//}
	//else{
	//	mToolBar = new ToolBarSlice(this);
	//}
	mToolBar = new ToolBarSlice(this);
	//
	QVBoxLayout *h = new QVBoxLayout(this);
	h->setMargin(1);
	h->setSpacing(0);
	h->setAlignment(Qt::AlignTop);
	h->addWidget(mToolBar);
 
	layout->addLayout(h);
	//
	this->setLayout(layout);
	//setMinimumHeight(200);

}

ImageWidget::~ImageWidget()
{
}



static QCursor LoadCursor(const QString &curfile, const QString &label = QString())
{
	int hotspot_x = 0, hotspot_y = 0;
	// read hotspot from the first icon.
	if (curfile.mid(curfile.length() - 4).compare(".cur", Qt::CaseInsensitive) == 0) {
		// A curfile, read it.
		QFile f(curfile);
		if (f.open(QIODevice::ReadOnly)) {
#pragma pack(push)
#pragma pack(2)
			struct FileHdr {
				ushort reserved;
				ushort type;
				ushort ic;
			};
#pragma pack(pop)
			struct IconHdr {
				uchar w;
				uchar h;
				uchar c;
				uchar r;
				ushort hotx;
				ushort hoty;
				quint32 bytes;
				quint32 off;
			};
			char buffer[sizeof(FileHdr) + sizeof(IconHdr)];
			f.read(buffer, sizeof(buffer));
			IconHdr* hdr = reinterpret_cast<IconHdr*>(&buffer[sizeof(FileHdr)]);
			hotspot_x = hdr->hotx;
			hotspot_y = hdr->hoty;
			//
			f.close();
		}
	}
	QPixmap pix(curfile);
	QPainter p(&pix);
	p.setFont(QFont("Times New Roman", 10));
	p.setBrush(QColor(0, 255, 0));
	p.setPen(QPen(QColor(0, 255, 0)));
	if (!label.isEmpty()) {
		p.drawText(pix.rect(), label, Qt::AlignRight | Qt::AlignBottom);
	}

	return QCursor(pix, hotspot_x, hotspot_y);
}

bool ImageWidget::IsViewMaximized()const
{
	return mView ? mView->IsViewMaximized((SlicePane)mPane) : false;
}

void ImageWidget::RestoreView()
{
	if (mView){
		mView->DoRelayout();
	}
}

void ImageWidget::MaximizeView()
{
	if (mView){
		mView->MaximizeView((SlicePane)mPane);
	}
}

QtMyShow *ImageWidget::GetView() const
{
	return mView;
}
