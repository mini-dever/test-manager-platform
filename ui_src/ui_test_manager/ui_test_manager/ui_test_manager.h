#pragma once

#include <QtWidgets/QMainWindow>
#include <ui_ui_test_manager.h>
#include "UITools.h"
#include "file_folder_manager.h"

class ui_test_manager : public QMainWindow
{
	Q_OBJECT
public:
	ui_test_manager(QWidget *parent = Q_NULLPTR);

private:
	Ui::ui_test_managerClass ui;
	UITest::UITools *_ui_tools;
	UITest::file_folder_manager* _ui_file_folder_manager;
};
