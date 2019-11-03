#pragma once
#include <QObject>
#include <QStringListModel>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>

namespace UITest
{
	class use_case_manager : public QObject
	{
	public:
		use_case_manager(QTreeView* list_view);

	private:
		QTreeView* _ui_list_view;
		QStandardItemModel* _item_model;
	};
}