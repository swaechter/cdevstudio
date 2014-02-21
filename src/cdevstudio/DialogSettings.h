#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QtWidgets/QDialog>

#include "ui_DialogSettings.h"

class DialogSettings : public QDialog, private Ui::DialogSettings
{
	Q_OBJECT
	
public:
	DialogSettings(QWidget *parent);
};

#endif // DIALOGSETTINGS_H
