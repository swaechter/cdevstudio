#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>

class DialogSettings : public QDialog
{
	Q_OBJECT
	
public:
	DialogSettings(QWidget *parent);
};

#endif // DIALOGSETTINGS_H
