#ifndef CDEVSTUDIOPLATFORMPLUGIN_H
#define CDEVSTUDIOPLATFORMPLUGIN_H

#include "CDevStudioPlatformExport.h"
#include "CDevStudioWindowManager.h"
#include "CDevStudioProjectManager.h"
#include "CDevStudioBackend.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatformPlugin
{
public:
	CDevStudioPlatformPlugin(CDevStudioWindowManager *windowmanager, CDevStudioProjectManager *projectmanager);
	CDevStudioWindowManager *getWindowManager();
	CDevStudioProjectManager *getProjectManager();
	CDevStudioBackend *getBackend();
	
private:
	CDevStudioWindowManager *m_WindowManager;
	CDevStudioProjectManager *m_ProjectManager;
	CDevStudioBackend m_Backend;
};

#endif // CDEVSTUDIOPLATFORMPLUGIN_H
