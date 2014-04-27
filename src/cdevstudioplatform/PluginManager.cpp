#include "PluginManager.h"

PluginManager::PluginManager() : QObject()
{
}

PluginManager::~PluginManager()
{
}

void PluginManager::loadPlugins()
{
	foreach(QString path, m_Backend.getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(m_Backend.getPluginFilter());
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file, this);
			QObject *object = loader.instance();
			if(object != nullptr)
			{
				IPlugin *plugin = qobject_cast<IPlugin *>(object);
				if(plugin != nullptr)
				{
					m_Plugins.append(plugin);
				}
			}
		}
	}
}

QList<IPlugin *> PluginManager::getPlugins()
{
	return m_Plugins;
}
