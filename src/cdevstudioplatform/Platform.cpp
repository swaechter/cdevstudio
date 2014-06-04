#include "Platform.h"

Platform::Platform(Window *window): PluginPlatform(window)
{
	m_PluginManager = new PluginManager(this);
	m_ProjectManager = new ProjectManager(this);
	m_WindowManager = new WindowManager(window, this);
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

WindowManager *Platform::getWindowManager()
{
	return m_WindowManager;
}
