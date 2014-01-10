#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QtWidgets/QDialog>

#include "ui_DialogAbout.h"
#include "Utils.h"

class DialogAbout : public QDialog, Ui::DialogAbout
{
	Q_OBJECT
	
public:
	DialogAbout(QWidget *parent);
};

#endif // DIALOGABOUT_H
