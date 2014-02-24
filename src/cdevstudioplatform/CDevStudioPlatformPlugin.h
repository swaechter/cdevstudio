#ifndef CDEVSTUDIOPLATFORMPLUGIN_H
#define CDEVSTUDIOPLATFORMPLUGIN_H

#include <QtCore/QString>
#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioWindow.h"
#include "CDevStudioBackend.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatformPlugin
{
public:
	CDevStudioPlatformPlugin(CDevStudioWindow *window, CDevStudioBackend *backend);
	CDevStudioWindow *getWindow();
	void setPlugins(QList<ICDevStudioPlugin *> plugins);
	QList<ICDevStudioPlugin *> getPlugins();
	CDevStudioBackend *getBackend();
	
private:
	CDevStudioWindow *parentWindow;
	QList<ICDevStudioPlugin *> parentPlugins;
	CDevStudioBackend *parentBackend;
};

#endif // CDEVSTUDIOPLATFORMPLUGIN_H
