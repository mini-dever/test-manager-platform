#pragma once
#include <QObject>
#include <QTreeView>

namespace UITest
{
	class file_folder_manager : public QObject
	{
	public:
		file_folder_manager(QTreeView *tree_view);
		Q_OBJECT
	public slots:

	private:
		QTreeView* _tree_view;
	};
}

