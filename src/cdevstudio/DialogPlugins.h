#ifndef DIALOGPLUGINS_H
#define DIALOGPLUGINS_H

#include <QtWidgets/QDialog>
#include <QtCore/QList>
#include <cdevstudioplatform/ICDevStudioPlugin.h>

#include "ui_DialogPlugins.h"

class DialogPlugins : public QDialog, private Ui::DialogPlugins
{
	Q_OBJECT
	
public:
	DialogPlugins(QList<ICDevStudioPlugin *> plugins, QWidget *parent);
};

#endif // DIALOGPLUGINS_H
