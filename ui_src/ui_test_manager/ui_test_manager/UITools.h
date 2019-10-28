#pragma once
#include <QObject>
namespace UITest
{
	class UITools : public QObject
	{
		Q_OBJECT
	public slots:
		void ClickOpenFolderButton();
		void ClickNewFileButton();
		void ClickSaveButton();

	private:
		QString  _root_path; // ��Ŀ¼
		QString  _cur_select_path; // ��ǰѡ���Ŀ¼
	};
}