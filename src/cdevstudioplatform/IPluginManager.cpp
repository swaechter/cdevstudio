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
	foreach(QString path, getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(getPluginFilter());
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

QStringList IPluginManager::getPluginFilter()
{
	QStringList filter;
	
#ifdef Q_OS_
	filter << QString("*plugin*.dylib");
#elseif Q_OS_WIN
	filter << QString("*plugin*.dll");
#else
	filter <<  QString("*plugin*.so");
#endif
	
	return filter;
}

QStringList IPluginManager::getPluginDirectories()
{
	QStringList directories;
	
#ifdef Q_OS_WIN
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/plugincore/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginproject/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginprojectwizard/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginprojectexplorer/";
#else
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/plugincore/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginproject/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectwizard/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectexplorer/";
#endif
	
	return directories;
}
