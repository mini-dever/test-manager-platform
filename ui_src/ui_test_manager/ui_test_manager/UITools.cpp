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

		// tode ��߸�Ŀ¼�л�����Ӧ�ļ���
	}

	void UITools::ClickNewFileButton()
	{
		if (_cur_select_path.isEmpty() && _root_path.isEmpty())
		{
			QMessageBox::information(nullptr, QStringLiteral("��ʾ"), QStringLiteral("����ѡ��һ������Ŀ¼"));
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
