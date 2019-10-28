#include <QMessageBox>
#include <QFileDialog>
#include <QLineEdit>
#include "UITools.h"

namespace UITest
{
	void UITools::ClickOpenFolderButton()
	{
		QString caption;
		QString dir;

		_root_path = QFileDialog::getExistingDirectory( nullptr, caption, dir);

		// tode 左边根目录切换到相应文件树
	}

	void UITools::ClickNewFileButton()
	{
		if (_cur_select_path.isEmpty() && _root_path.isEmpty())
		{
			QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("请先选择一个工作目录"));
		}
		QString user_path = _cur_select_path;
		if (_cur_select_path.isEmpty())
		{
			user_path = _root_path;
		}
		QLineEdit* lien_edit = new QLineEdit("123");
		
	}

	void UITools::ClickSaveButton()
	{

	}
}
