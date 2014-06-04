#include "Platform.h"

Platform::Platform(QObject *parent): PluginPlatform(parent)
{
	m_PluginManager = new PluginManager(this);
	m_ProjectManager = new ProjectManager(this);
	m_PluginManager->loadPlugins();
}

Platform::~Platform()
{
	delete m_PluginManager;
}

PluginManager *Platform::getPluginManager()
{
	return m_PluginManager;
}

ProjectManager *Platform::getProjectManager()
{
	return m_ProjectManager;
}
