#include "SettingsPage.h"

SettingsPage::SettingsPage(QWidget *parent, QString name)
{
	m_Name = name;
}

QString SettingsPage::getName()
{
	return m_Name;
}
