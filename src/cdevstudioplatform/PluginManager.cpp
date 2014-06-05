#include "PluginManager.h"

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{

}

void PluginManager::loadPlugins()
{
	if(m_Plugins.count() == 0)
	{
		foreach(QString path, Backend::getPluginDirectories())
		{
			foreach(QString file, Backend::getFilesInDirectory(path))
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
