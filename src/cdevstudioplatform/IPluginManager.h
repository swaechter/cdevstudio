#ifndef IPLUGINMANAGER_H
#define IPLUGINMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDir>
#include <QtCore/QPluginLoader>

#include "PlatformExport.h"
#include "IPlugin.h"

#include <QDebug>

class CDEVSTUDIOPLATFORM_EXPORT IPluginManager : public QObject
{
	Q_OBJECT
	
public:
	IPluginManager();
	~IPluginManager();
	void loadPlugins();
	QList<IPlugin *> getPlugins();
	IPlugin *getPlugin(QString name);
	
private:
	QList<IPlugin *> m_Plugins;
	
	QStringList getPluginFilter();
	QStringList getPluginDirectories();
};

#endif // IPLUGINMANAGER_H
