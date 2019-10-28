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
		QString  _root_path; // 根目录
		QString  _cur_select_path; // 当前选择的目录
	};
}