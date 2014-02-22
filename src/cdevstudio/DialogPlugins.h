#ifndef DIALOGPLUGINS_H
#define DIALOGPLUGINS_H

#include <QtWidgets/QDialog>

#include "ui_DialogPlugins.h"

class DialogPlugins : public QDialog, private Ui::DialogPlugins
{
	Q_OBJECT
	
public:
	DialogPlugins(QWidget *parent);
};

#endif // DIALOGPLUGINS_H
