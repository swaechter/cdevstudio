#include "CDevStudioPlatformPlugin.h"

CDevStudioPlatformPlugin::CDevStudioPlatformPlugin(CDevStudioWindow *window, QList<ICDevStudioPlugin *> plugins, CDevStudioBackend *backend)
{
	parentWindow = window;
	parentPlugins = plugins;
	parentBackend = backend;
}

CDevStudioWindow *CDevStudioPlatformPlugin::getWindow()
{
	return parentWindow;
}

QList<ICDevStudioPlugin *> CDevStudioPlatformPlugin::getPlugins()
{
	return parentPlugins;
}

CDevStudioBackend *CDevStudioPlatformPlugin::getBackend()
{
	return parentBackend;
}
