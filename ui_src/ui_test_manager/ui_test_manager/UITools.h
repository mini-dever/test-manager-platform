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
	signals:
		void RootPathValueChanged(QString root_path);
	public:
		QString  _root_path; // ��Ŀ¼
		QString  _cur_select_path; // ��ǰѡ���Ŀ¼
		QMainWindow* _parent_frame; // ��ҳ��
	};
}