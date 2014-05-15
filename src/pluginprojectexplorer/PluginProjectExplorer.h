#ifndef PLUGINPROJECTEXPLORER_H
#define PLUGINPROJECTEXPLORER_H

#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPluginManager.h>
#include <cdevstudioplatform/IPlugin.h>
#include <plugincore/PluginCore.h>
#include <plugincore/Window.h>
#include <pluginproject/PluginProjects.h>

#include "PluginProjectExplorerExport.h"

class PLUGINPROJECTEXPLORER_EXPORT PluginProjectExplorer : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginProjectExplorer();
	~PluginProjectExplorer();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	PluginCore *m_PluginCore;
	PluginProjects *m_PluginProjects;
};

#endif // PLUGINPROJECTEXPLORER_H