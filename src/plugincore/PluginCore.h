#ifndef PLUGINPROJECT_H
#define PLUGINPROJECT_H

#include <QtCore/QObject>
#include <cdevstudioplatform/IPlugin.h>

#include "PluginCoreExport.h"
#include "Window.h"

#include <QtDebug>

class PLUGINCORE_EXPORT PluginCore : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudio.IPlugin")
	
public:
	PluginCore();
	~PluginCore();
	QString getName();
	QString getVersion();
	QString getDescription();
	Window *getWindow();
	
private:
	Window *m_Window;
};

#endif // PLUGINPROJECT_H
