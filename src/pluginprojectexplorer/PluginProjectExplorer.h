#ifndef PLUGINPROJECTEXPLORER_H
#define PLUGINPROJECTEXPLORER_H

#include <QtCore/QObject>
#include <cdevstudioplatform/PluginPlatform.h>
#include <cdevstudioplatform/PluginManager.h>
#include <cdevstudioplatform/Plugin.h>

#include "PluginProjectExplorerExport.h"

class PLUGINPROJECTEXPLORER_EXPORT PluginProjectExplorer : public Plugin
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.Plugin")
	
public:
	PluginProjectExplorer();
	~PluginProjectExplorer();
	QString getName();
	QString getVersion();
	QString getDescription();
};

#endif // PLUGINPROJECTEXPLORER_H
