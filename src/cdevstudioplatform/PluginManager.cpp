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
	if(m_Plugins.count() == 0)
	{
		foreach(QString path, getPluginDirectories())
		{
			foreach(QString file, QDir(path).entryList())
			{
				QString filepath = path + file;
				if(QLibrary::isLibrary(filepath))
				{
					QPluginLoader loader(filepath, this);
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
	}
}

QList<Plugin *> PluginManager::getPlugins()
{
	return m_Plugins;
}

QStringList PluginManager::getPluginDirectories()
{
	QStringList directories;
	
#ifdef Q_OS_WIN
	directories << "C:/Users/swaechter/Downloads/cdevstudio/build/src/pluginprojects/";
	directories << "C:/Users/swaechter/Downloads/cdevstudio/build/src/pluginprojectexplorer/";
#else
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojects/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectexplorer/";
#endif
	
	return directories;
}
