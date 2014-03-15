#ifndef CDEVSTUDIOPLATFORM_H
#define CDEVSTUDIOPLATFORM_H

#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioPlatformPlugin.h"
#include "CDevStudioWindowManager.h"
#include "CDevStudioWindow.h"
#include "CDevStudioPluginManager.h"
#include "CDevStudioProjectManager.h"
#include "CDevStudioBackend.h"
#include "CDevStudioProjectTemplate.h"
#include "CDevStudioProject.h"
#include "CDevStudioBackend.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatform
{
public:
	CDevStudioPlatform(CDevStudioWindow *window);
	~CDevStudioPlatform();
	void initPlugins();
	CDevStudioWindowManager *getWindowManager();
	CDevStudioPluginManager *getPluginManager();
	CDevStudioProjectManager *getProjectManager();
	
private:
	CDevStudioPlatformPlugin *m_PlatformPlugins;
	CDevStudioWindowManager *m_WindowManager;
	CDevStudioPluginManager *m_PluginManager;
	CDevStudioProjectManager *m_ProjectManager;
};

#endif // CDEVSTUDIOPLATFORM_H
