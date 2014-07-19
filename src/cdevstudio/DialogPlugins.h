#ifndef DIALOGPLUGINS_H
#define DIALOGPLUGINS_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView.h>
#include <QtCore/QList>
#include <cdevstudioplatform/PluginContainer.h>
#include <cdevstudioplatform/IPlugin.h>

#include "ui_DialogPlugins.h"

class DialogPlugins : public QDialog, private Ui::DialogPlugins
{
	Q_OBJECT
	
public:
	DialogPlugins(QWidget *parent, QList<PluginContainer *> plugincontainers);
};

#endif // DIALOGPLUGINS_H
