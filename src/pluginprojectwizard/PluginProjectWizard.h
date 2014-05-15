#ifndef PLUGINPROJECTWIZARD_H
#define PLUGINPROJECTWIZARD_H

#include <QtWidgets/QAction>
#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPluginManager.h>
#include <cdevstudioplatform/IPlugin.h>
#include <plugincore/PluginCore.h>
#include <pluginproject/PluginProjects.h>

#include "PluginProjectWizardExport.h"

#include <QtCore/QDebug>

class PLUGINPROJECTWIZARD_EXPORT PluginProjectWizard : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginProjectWizard();
	~PluginProjectWizard();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	PluginCore *m_PluginCore;
	PluginProjects *m_PluginProjects;
	QAction *m_CreateProject;
	QAction *m_LoadProject;
	QAction *m_CloseProject;
	
private slots:
	void actionCreateProject();
	void actionLoadProject();
	void actionCloseProject();
};

#endif // PLUGINPROJECTWIZARD_H
