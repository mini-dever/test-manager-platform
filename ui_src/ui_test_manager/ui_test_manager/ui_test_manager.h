#pragma once

#include <QtWidgets/QMainWindow>
#include <ui_ui_test_manager.h>

class ui_test_manager : public QMainWindow
{
	Q_OBJECT
public:
	ui_test_manager(QWidget *parent = Q_NULLPTR);

private:
	Ui::ui_test_managerClass ui;
};
