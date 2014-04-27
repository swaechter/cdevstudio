#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "PlatformExport.h"
#include "Backend.h"
#include "interfaces/IPlugin.h"

#include <QtCore/QDebug>

class CDEVSTUDIOPLATFORM_EXPORT PluginManager : public QObject
{
	Q_OBJECT
	
public:
	PluginManager();
	~PluginManager();
	void loadPlugins();
	QList<IPlugin *> getPlugins();
	
private:
	QList<IPlugin *> m_Plugins;
};

#endif // PLUGINMANAGER_H
