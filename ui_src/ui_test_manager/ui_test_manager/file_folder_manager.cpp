#include "file_folder_manager.h"
#include "common_icon.h"
#include <QStandardItemModel>
#include <QStandardItem>

namespace UITest
{
	file_folder_manager::file_folder_manager(QTreeView* tree_view)
	{
		_tree_view = tree_view;
		QStandardItemModel* model = new QStandardItemModel(_tree_view);
		model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("�ļ���"));

		QStandardItem* itemProject = new QStandardItem(commom_icon::get_instance()->GetIcon(QStringLiteral("treeItem_folder")), QStringLiteral("�½��ļ���"));
		model->appendRow(itemProject);

		_tree_view->setModel(model);
	}
}