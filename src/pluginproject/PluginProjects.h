#ifndef PLUGINPROJECTS_H
#define PLUGINPROJECTS_H

#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPluginManager.h>
#include <cdevstudioplatform/IPlugin.h>
#include <plugincore/PluginCore.h>

#include "PluginProjectsExport.h"

#include <QtCore/QDebug>

class PLUGINPROJECTS_EXPORT PluginProjects : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginProjects();
	~PluginProjects();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	PluginCore *m_PluginCore;
};

#endif // PLUGINPROJECTS_H
