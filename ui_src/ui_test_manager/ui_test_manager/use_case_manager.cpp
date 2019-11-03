#include "use_case_manager.h"

namespace UITest
{
	use_case_manager::use_case_manager(QTreeView* list_view)
	{
		_ui_list_view = list_view;
		QStandardItemModel* _item_model = new QStandardItemModel(list_view);
		_item_model->setHorizontalHeaderLabels(QStringList() << QStringLiteral("     key") << QStringLiteral("     value"));

		QStringList strList;
		strList.append("type");
		strList.append("data");
		strList.append("host");
		strList.append("port");
		strList.append("src_file");
		strList.append("pwd");
		strList.append("des_file");
		strList.append("write_way");

		int nCount = strList.size();
		for (int i = 0; i < nCount; i++)
		{
			QString string = static_cast<QString>(strList.at(i));
			QStandardItem* item = new QStandardItem(string);
			_item_model->appendRow(item);
		}
		_ui_list_view->setModel(_item_model);
		//_ui_list_view->setFixedSize(200, 300);

	}
}