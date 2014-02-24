#ifndef CDEVSTUDIOPLATFORMPLUGIN_H
#define CDEVSTUDIOPLATFORMPLUGIN_H

#include <QtCore/QString>
#include <QtCore/QList>

#include "CDevStudioWindow.h"
#include "CDevStudioBackend.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatformPlugin
{
public:
	CDevStudioPlatformPlugin(CDevStudioWindow *window, CDevStudioBackend *backend);
	CDevStudioWindow *getWindow();
	CDevStudioBackend *getBackend();
	QList<ICDevStudioPlugin *> getPlugins();
	
private:
	CDevStudioWindow *parentWindow;
	CDevStudioBackend *parentBackend;
};

#endif // CDEVSTUDIOPLATFORMPLUGIN_H
