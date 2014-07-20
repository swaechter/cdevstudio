#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets/QDialog>

#include "PlatformExport.h"
#include "SettingsPage.h"

class CDEVSTUDIOPLATFORM_EXPORT Settings : public QDialog
{
	Q_OBJECT
	
public:
	Settings(QWidget *parent);
	void addSettingsPage(SettingsPage *settingspage);
	
private:
	QList<SettingsPage *> m_SettingsPages;
};

#endif // SETTINGS_H
