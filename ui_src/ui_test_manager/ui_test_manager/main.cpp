#include "ui_test_manager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ui_test_manager w;
	w.show();
	return a.exec();
}
