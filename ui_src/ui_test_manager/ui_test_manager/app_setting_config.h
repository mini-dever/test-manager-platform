#pragma once
#include <QString>
#include <QCoreApplication>
#include <QSettings>
#include <QFileInfo>

namespace config
{
	class app_setting_config;
	class config_data
	{
	public:
		QString _select_path = ""; // ��ǰѡ��Ŀ¼

		// ��Ҫ���ػ������������ں������

		void Load();

		void Save();
	};

	class app_setting_config
	{
	public:
		friend class config_data;
		// ����App�������ļ�,ֻ��Ҫ����һ��
		static void LoadAppConfigFile()
		{
			if (_data != nullptr)
			{
				delete _data;
				_data = nullptr;
			}
			_data = new config_data();

			QString config_file_name = QCoreApplication::applicationDirPath() + "/Config.ini";
			_setting = new QSettings(config_file_name, QSettings::IniFormat);

			QFileInfo fileInfo(config_file_name);
			if (fileInfo.exists())
			{
				_data->Load();
			}
		}

		// ����ʱ����
		static void SaveFile()
		{
			_data->Save();
		}

		// ����������Ϣ
		static config_data* GetConfigData()
		{
			return _data;
		}

	private:
		static void SetConfigData(QString qstrnodename, QString qstrkeyname, QVariant qvarvalue)
		{
			if (_setting) {
				_setting->setValue(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname), qvarvalue);
			}
		}

		static QVariant GetConfigData(QString qstrnodename, QString qstrkeyname)
		{
			QVariant qvar = -1;
			if (_setting) {
				qvar = _setting->value(QString("/%1/%2").arg(qstrnodename).arg(qstrkeyname));
			}
			return qvar;
		}

		static config_data* _data;
		static QSettings* _setting;
	};
}
