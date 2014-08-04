#ifndef PLUGINTOOLCHAIN_H
#define PLUGINTOOLCHAIN_H

#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPlugin.h>

#include "PluginToolchainExport.h"
#include "PluginPage.h"

class PLUGINTOOLCHAIN_EXPORT PluginToolchain : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin" FILE "PluginToolchain.json")
	
public:
	PluginToolchain();
	~PluginToolchain();
	
private:
	IPlatform *m_Platform;
};

#endif // PLUGINTOOLCHAIN_H
