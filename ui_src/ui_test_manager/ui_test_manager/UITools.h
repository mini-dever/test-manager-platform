#pragma once
#include <QObject>
#include <QtWidgets/QMainWindow>
namespace UITest
{
	class UITools : public QObject
	{
		Q_OBJECT
	public slots:
		void ClickOpenFolderButton();
		void ClickNewFileButton();
		void ClickSaveButton();

		void SetParentFrame(QObject* obj);
		void SendSingal(QString path);
	signals:
		void RootPathValueChanged(QString root_path);
	public:
		QString  _root_path; // 根目录
		QString  _cur_select_path; // 当前选择的目录
		QMainWindow* _parent_frame; // 父页面
	};
}