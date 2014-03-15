#include "CDevStudioPlatformPlugin.h"

CDevStudioPlatformPlugin::CDevStudioPlatformPlugin(CDevStudioWindowManager *windowmanager, CDevStudioProjectManager *projectmanager)
{
	m_WindowManager = windowmanager;
	m_ProjectManager = projectmanager;
}

CDevStudioWindowManager *CDevStudioPlatformPlugin::getWindowManager()
{
	return m_WindowManager;
}

CDevStudioProjectManager *CDevStudioPlatformPlugin::getProjectManager()
{
	return m_ProjectManager;
}

CDevStudioBackend *CDevStudioPlatformPlugin::getBackend()
{
	return &m_Backend;
}
