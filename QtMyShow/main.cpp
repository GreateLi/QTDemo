#include "QtMyShow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtMyShow w;
	w.showMaximized();
	//w.show();
	return a.exec();
}
