#include "ui_test_manager.h"
#include "UITools.h"
#include <QMessageBox>

ui_test_manager::ui_test_manager(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_ui_tools = new UITest::UITools();
	_ui_file_folder_manager = new UITest::file_folder_manager(ui.treeView);

	_ui_tools->SetParentFrame(this);
	bool c1 = connect(ui.button_open_folder, SIGNAL(clicked()), _ui_tools, SLOT(ClickOpenFolderButton()));
	bool c2 = connect(ui.button_new_file, SIGNAL(clicked()), _ui_tools, SLOT(ClickNewFileButton()));
	bool c3 = connect(ui.button_save, SIGNAL(clicked()), _ui_tools, SLOT(ClickSaveButton()));

	_ui_tools->ClickOpenFolderButton();
}

