#ifndef DIALOGHELP_H
#define DIALOGHELP_H

#include <QtWidgets/QDialog>

#include "ui_DialogHelp.h"

class DialogHelp : public QDialog, private Ui::DialogHelp
{
	Q_OBJECT
	
public:
	DialogHelp(QWidget *parent);
};

#endif // DIALOGHELP_H
