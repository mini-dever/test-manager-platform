#include <QMessageBox>
#include <QFileDialog>
#include <QTextEdit>
#include "UITools.h"
#include "input_dialog.h"

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
		input_dialog*textEdit = new input_dialog();
		//textEdit->setGeometry(QRect(150, 100, 200, 200));
		textEdit->_cur_path = user_path;
		textEdit->exec();
		QString name = textEdit->_text;
		delete textEdit;
		textEdit = nullptr;


	}

	void UITools::ClickSaveButton()
	{
		
	}

	void UITools::SetParentFrame(QObject* obj)
	{
		_parent_frame = (QMainWindow*)obj;
	}
}
