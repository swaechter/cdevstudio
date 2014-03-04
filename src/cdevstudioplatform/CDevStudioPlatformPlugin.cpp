#include "CDevStudioPlatformPlugin.h"

CDevStudioPlatformPlugin::CDevStudioPlatformPlugin(CDevStudioWindow *window, CDevStudioBackend *backend, CDevStudioData *data) : QObject()
{
	parentWindow = window;
	parentBackend = backend;
	parentData = data;
}

CDevStudioWindow *CDevStudioPlatformPlugin::getWindow()
{
	return parentWindow;
}

CDevStudioBackend *CDevStudioPlatformPlugin::getBackend()
{
	return parentBackend;
}

CDevStudioData *CDevStudioPlatformPlugin::getData()
{
	return parentData;
}

void CDevStudioPlatformPlugin::addProjectTemplate(CDevStudioProjectTemplate projecttemplate)
{
	emit addPlatformProjectTemplate(projecttemplate);
}
