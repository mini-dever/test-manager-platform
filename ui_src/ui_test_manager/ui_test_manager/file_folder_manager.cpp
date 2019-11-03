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
		_model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("�ļ���"));

		_tree_view->setModel(_model);
	}

	void file_folder_manager::OnChangeRootPath(QString root_path)
	{
		if (root_path.isEmpty())
		{
			return;
		}
		// ɾ��ԭ�пؼ�

		// �����µĿؼ�������Ŀ¼
		QDir file_dir(root_path);

		QFileInfoList file_info_list = file_dir.entryInfoList();


		for (int i = 0; i < file_info_list.count(); i++)
		{
			QString name = file_info_list.at(i).fileName();
			if (file_info_list.at(i).isDir()) // ���ļ���
			{
				QStandardItem* itemProject = new QStandardItem(commom_icon::get_instance()->GetIcon(QStringLiteral("tree_item_folder")), name);
				_model->appendRow(itemProject);

				// todo �ݹ�
			}
			else if (file_info_list.at(i).isFile()) // ���ļ�
			{
				QStandardItem* itemProject = new QStandardItem(commom_icon::get_instance()->GetIcon(QStringLiteral("tree_item_file")), name);
				_model->appendRow(itemProject);
			}
		}
	}
}