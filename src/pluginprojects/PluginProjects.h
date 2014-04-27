#ifndef PLUGINPROJECTS_H
#define PLUGINPROJECTS_H

#include <QtCore/QObject>
#include <cdevstudioplatform/interfaces/IPlugin.h>
#include <cdevstudioplatform/Platform.h>

#include "PluginProjectsExport.h"

#include <QtCore/QDebug>

class PLUGINPROJECTS_API PluginProjects : public QObject, private IPlugin
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
};

#endif // PLUGINPROJECTS_H
