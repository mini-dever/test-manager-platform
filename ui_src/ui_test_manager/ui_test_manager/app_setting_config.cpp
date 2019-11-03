#include "app_setting_config.h"

namespace config
{
	config_data* app_setting_config::_data = nullptr;
	QSettings* app_setting_config::_setting = nullptr;

	void config_data::Load()
	{
		_select_path = app_setting_config::GetConfigData("select_path", "path").toString();
	}

	void config_data::Save()
	{
		app_setting_config::SetConfigData("select_path", "path", _select_path);
	}
}