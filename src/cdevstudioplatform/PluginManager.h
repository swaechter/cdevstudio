#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDir>
#include <QtCore/QPluginLoader>

#include "PlatformExport.h"
#include "Plugin.h"

#include <QDebug>

class CDEVSTUDIOPLATFORM_EXPORT PluginManager : public QObject
{
	Q_OBJECT
	
public:
	PluginManager(QObject *parent);
	void loadPlugins();
	QList<Plugin *> getPlugins();
	
private:
	QList<Plugin *> m_Plugins;
	
	QStringList getPluginDirectories();
};

#endif // PLUGINMANAGER_H
