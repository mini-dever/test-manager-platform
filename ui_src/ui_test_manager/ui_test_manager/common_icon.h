#pragma once
#include <QMap>
#include <QIcon>

class commom_icon
{
private:
	commom_icon()
	{
		Init();
	}

	void Init()
	{
		_icon_map[QStringLiteral("tree_item_folder")] = QIcon(QStringLiteral("Resources/FileFolder.png"));
		_icon_map[QStringLiteral("tree_item_file")] = QIcon(QStringLiteral("Resources/File.png"));
	}
public:
	static commom_icon* get_instance()
	{
		if (_instance == nullptr)
		{
			_instance = new commom_icon();
		}
		return _instance;
	}

	// ªÒ»°Õº±Í
	QIcon& GetIcon(QString key)
	{
		return _icon_map[key];
	}
private:
	static commom_icon* _instance;
	QMap<QString, QIcon> _icon_map;
};
