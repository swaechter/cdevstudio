#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDir>
#include <QtCore/QPluginLoader>
#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

#include "PlatformExport.h"
#include "Plugin.h"
#include "Backend.h"

class CDEVSTUDIOPLATFORM_EXPORT PluginManager : public QObject
{
	Q_OBJECT
	
public:
	PluginManager(QObject *parent);
	QList<Plugin *> getPlugins();
	
private:
	QList<Plugin *> m_Plugins;
};

#endif // PLUGINMANAGER_H
