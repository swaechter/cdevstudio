#include "CDevStudioPluginManager.h"

CDevStudioPluginManager::CDevStudioPluginManager() : QObject()
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
				ICDevStudioPlugin *plugin = qobject_cast<ICDevStudioPlugin *>(object);
				if(plugin != nullptr)
				{
					m_Plugins.append(plugin);
				}
			}
		}
	}
}

CDevStudioPluginManager::~CDevStudioPluginManager()
{

}

void CDevStudioPluginManager::initPlugins(CDevStudioPlatformPlugin *platformplugin)
{
	foreach(ICDevStudioPlugin *plugin, m_Plugins)
	{
		plugin->init(platformplugin);
	}
}

QList<ICDevStudioPlugin *> CDevStudioPluginManager::getPlugins()
{
	return m_Plugins;
}
