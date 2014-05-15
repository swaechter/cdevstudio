#include "Platform.h"

Platform::Platform(QObject *parent): IPlatform(parent)
{
	m_PluginManager = new IPluginManager();
	m_PluginManager->loadPlugins();
}

Platform::~Platform()
{
	delete m_PluginManager;
}

IPluginManager *Platform::getPluginManager()
{
	return m_PluginManager;
}