#include "PluginManager.h"

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{

}

PluginManager::~PluginManager()
{
	qDeleteAll<>(m_Plugins);
}

void PluginManager::loadPlugins()
{
	foreach(QString path, getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(getPluginFilter());
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file, this);
			Plugin *plugin = qobject_cast<Plugin *>(loader.instance());
			if(plugin != nullptr)
			{
					m_Plugins.append(plugin);
			}
			else
			{
				qDebug() << "Error:" << loader.errorString();
			}
		}
	}
}

QList<Plugin *> PluginManager::getPlugins()
{
	return m_Plugins;
}

Plugin *PluginManager::getPlugin(QString name)
{
	Plugin *searchplugin = nullptr;
	foreach(Plugin *plugin, m_Plugins)
	{
		if(name.compare(plugin->getName()) == 0)
		{
			searchplugin = plugin;
		}
	}
	return searchplugin;
}

QStringList PluginManager::getPluginFilter()
{
	QStringList filter;
	filter << QString("*plugin*.dylib");
	filter << QString("*plugin*.dll");
	filter <<  QString("*plugin*.so");
	return filter;
}

QStringList PluginManager::getPluginDirectories()
{
	QStringList directories;
	
#ifdef Q_OS_WIN
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginprojects/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginprojectexplorer/";
#else
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojects/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectexplorer/";
#endif
	
	return directories;
}
