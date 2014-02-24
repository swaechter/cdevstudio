#include "CDevStudioPlatformPlugin.h"

CDevStudioPlatformPlugin::CDevStudioPlatformPlugin(CDevStudioWindow *window, CDevStudioBackend *backend)
{
	parentWindow = window;
	parentBackend = backend;
}

CDevStudioWindow *CDevStudioPlatformPlugin::getWindow()
{
	return parentWindow;
}

void CDevStudioPlatformPlugin::setPlugins(QList< ICDevStudioPlugin * > plugins)
{
	parentPlugins = plugins;
}

QList<ICDevStudioPlugin *> CDevStudioPlatformPlugin::getPlugins()
{
	return parentPlugins;
}

CDevStudioBackend *CDevStudioPlatformPlugin::getBackend()
{
	return parentBackend;
}
