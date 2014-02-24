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

CDevStudioBackend *CDevStudioPlatformPlugin::getBackend()
{
	return parentBackend;
}

QList<ICDevStudioPlugin *> CDevStudioPlatformPlugin::getPlugins()
{
	QList<ICDevStudioPlugin *> list; // TODO
	return list;
}
