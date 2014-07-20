#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QtWidgets/QWidget>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT SettingsPage : public QWidget
{
	Q_OBJECT
	
public:
	SettingsPage(QWidget *parent, QString name);
	QString getName();
	
private:
	QString m_Name;
};

#endif // SETTINGSPAGE_H
