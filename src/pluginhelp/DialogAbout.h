#ifndef PLUGINABOUT_H
#define PLUGINABOUT_H

#include <QtWidgets/QDialog>

#include "ui_DialogAbout.h"

class DialogAbout : public QDialog, private Ui::DialogAbout
{
	Q_OBJECT
	
public:
	DialogAbout(QWidget *parent);
};

#endif // PLUGINABOUT_H
