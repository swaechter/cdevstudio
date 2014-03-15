#include "CDevStudioPlatform.h"

CDevStudioPlatform::CDevStudioPlatform(CDevStudioWindow *window)
{
	m_WindowManager = new CDevStudioWindowManager(window);
	m_PluginManager = new CDevStudioPluginManager();
	m_ProjectManager = new CDevStudioProjectManager();
	m_PlatformPlugins = new CDevStudioPlatformPlugin(m_WindowManager, m_ProjectManager);
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	delete m_PlatformPlugins;
	delete m_PluginManager;
	delete m_ProjectManager;
}

void CDevStudioPlatform::initPlugins()
{
	m_PluginManager->initPlugins(m_PlatformPlugins);
}

CDevStudioWindowManager *CDevStudioPlatform::getWindowManager()
{
	return m_WindowManager;
}

CDevStudioPluginManager *CDevStudioPlatform::getPluginManager()
{
	return m_PluginManager;
}

CDevStudioProjectManager *CDevStudioPlatform::getProjectManager()
{
	return m_ProjectManager;
}
