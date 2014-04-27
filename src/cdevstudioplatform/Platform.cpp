#include "Platform.h"

Platform::Platform(Window *window): IPlatform(window)
{
	qDebug() << "Platform::Platform start";
	m_WindowManager = new WindowManager(window);
	m_PluginManager = new PluginManager();
	m_ProjectManager = new ProjectManager();
	qDebug() << "Platform::Platform end";
}

Platform::~Platform()
{
	qDebug() << "Platform::~Platform start";
	delete m_PluginManager;
	delete m_ProjectManager;
	delete m_WindowManager;
	qDebug() << "Platform::~Platform end";
}

WindowManager *Platform::getWindowManager()
{
	return m_WindowManager;
}

PluginManager *Platform::getPluginManager()
{
	return m_PluginManager;
}

ProjectManager *Platform::getProjectManager()
{
	return m_ProjectManager;
}
