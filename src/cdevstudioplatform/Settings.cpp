#include "Settings.h"

Settings::Settings(QWidget *parent)
{
}

void Settings::addSettingsPage(SettingsPage *settingspage)
{
	m_SettingsPages.append(settingspage);
}
