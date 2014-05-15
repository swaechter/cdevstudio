#include "IPluginManager.h"

IPluginManager::IPluginManager(): QObject()
{

}

IPluginManager::~IPluginManager()
{
	qDeleteAll<>(m_Plugins);
}

void IPluginManager::loadPlugins()
{
	foreach(QString path, Backend::getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(Backend::getPluginFilter());
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file, this);
			IPlugin *plugin = qobject_cast<IPlugin *>(loader.instance());
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
	
// 	QPluginLoader loader("/home/swaechter/Workspace_C++/cdevstudio_new/build/src/plugincore/libplugincore.so");
// // 	QPluginLoader *loader = new QPluginLoader("/home/swaechter/Workspace_C++/cdevstudio_new/build/src/plugincore/libplugincore.so");
// 	IPlugin *plugin = qobject_cast< IPlugin* >(loader.instance());
// 	if(plugin)
// 	{
// 		qDebug() << "Success";
// 		m_Plugins.append(plugin);
// 	}
// 	else
// 	{
// // 		delete loader;
// 	}
}

QList<IPlugin *> IPluginManager::getPlugins()
{
	return m_Plugins;
}

IPlugin *IPluginManager::getPlugin(QString name)
{
	IPlugin *searchplugin = nullptr;
	foreach(IPlugin *plugin, m_Plugins)
	{
		if(name.compare(plugin->getName()) == 0)
		{
			searchplugin = plugin;
		}
	}
	return searchplugin;
}