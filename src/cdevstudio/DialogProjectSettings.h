#ifndef DIALOGPROJECTSETTINGS_H
#define DIALOGPROJECTSETTINGS_H

#include <QtWidgets/QDialog>

#include "ui_DialogProjectSettings.h"

class DialogProjectSettings : public QDialog, Ui::DialogProjectSettings
{
	Q_OBJECT
	
public:
	DialogProjectSettings(QWidget *parent);
};

#endif // DIALOGPROJECTSETTINGS_H
