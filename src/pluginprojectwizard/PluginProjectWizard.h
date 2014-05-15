#ifndef PLUGINPROJECTWIZARD_H
#define PLUGINPROJECTWIZARD_H

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
};

#endif // PLUGINPROJECTWIZARD_H
