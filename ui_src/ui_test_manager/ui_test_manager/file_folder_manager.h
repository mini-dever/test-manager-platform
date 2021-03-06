#pragma once
#include <QObject>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>

namespace UITest
{
	class file_folder_manager : public QObject
	{
	public:
		file_folder_manager(QTreeView *tree_view);
		void CreateFileTree(QStandardItem *parent, QString path); // �����ļ���
		Q_OBJECT
	public slots:
		void OnChangeRootPath(QString root_path);
	private:
		QTreeView* _tree_view;
		QStandardItemModel* _model;
	};
}

