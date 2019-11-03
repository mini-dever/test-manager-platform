#include "file_folder_manager.h"
#include "common_icon.h"
#include <QStandardItem>
#include <QDir>

namespace UITest
{
	file_folder_manager::file_folder_manager(QTreeView* tree_view)
	{
		_tree_view = tree_view;
		_model = new QStandardItemModel(_tree_view);
		_model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("�ļ�Ŀ¼"));

		_tree_view->setModel(_model);
	}

	void file_folder_manager::OnChangeRootPath(QString root_path)
	{
		if (root_path.isEmpty())
		{
			return;
		}
		// ɾ��ԭ�пؼ�
		_model->removeRows(0, _model->rowCount());

		// �����µĿؼ�������Ŀ¼
		CreateFileTree(nullptr, root_path);
	}

	void file_folder_manager::CreateFileTree(QStandardItem *parent, QString path)
	{
		QDir file_dir(path);

		QFileInfoList file_info_list = file_dir.entryInfoList();


		for (int i = 0; i < file_info_list.count(); i++)
		{
			QString name = file_info_list.at(i).fileName();
			if (file_info_list.at(i).isDir()) // ���ļ���
			{
				QStandardItem* item_project = new QStandardItem(commom_icon::get_instance()->GetIcon(QStringLiteral("tree_item_folder")), name);
				
				if (parent != nullptr)
				{
					parent->appendRow(item_project);
				}
				else
				{
					_model->appendRow(item_project);
				}
				// todo �ݹ�
				if (name.compare(QString(".")) != 0 &&
					name.compare(QString("..")) != 0)
				CreateFileTree(item_project, file_info_list.at(i).filePath());
				
			}
			else if (file_info_list.at(i).isFile()) // ���ļ�
			{
				QStandardItem* item_project = new QStandardItem(commom_icon::get_instance()->GetIcon(QStringLiteral("tree_item_file")), name);
				if (parent != nullptr)
				{
					parent->appendRow(item_project);
				}
				else
				{
					_model->appendRow(item_project);
				}
			}
		}
	}
}