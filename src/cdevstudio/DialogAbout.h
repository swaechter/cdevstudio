#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QtWidgets/QDialog>

#include "ui_DialogAbout.h"

class DialogAbout : public QDialog, private Ui::DialogAbout
{
	Q_OBJECT
	
public:
	DialogAbout(QWidget *parent, QString abouttext, QString licensetext, QString thankstotext);
};

#endif // DIALOGABOUT_H
