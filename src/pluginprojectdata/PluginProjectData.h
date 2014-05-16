#ifndef PLUGINPROJECTDATA_H
#define PLUGINPROJECTDATA_H

#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPluginManager.h>
#include <cdevstudioplatform/IPlugin.h>
#include <plugincore/PluginCore.h>
#include <pluginproject/PluginProjects.h>

#include "PluginProjectDataExport.h"

class PLUGINPROJECTDATA_EXPORT PluginProjectData : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginProjectData();
	~PluginProjectData();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	PluginCore *m_PluginCore;
	PluginProjects *m_PluginProjects;
};

#endif // PLUGINPROJECTDATA_H
