#ifndef CDEVSTUDIOWINDOWMANAGER_H
#define CDEVSTUDIOWINDOWMANAGER_H

#include "CDevStudioPlatformExport.h"
#include "CDevStudioWindow.h"

class CDEVSTUDIOPLATFORM_API CDevStudioWindowManager
{
public:
	CDevStudioWindowManager(CDevStudioWindow *window);
	CDevStudioWindowManager();
	CDevStudioWindow *getWindow();
	
private:
	CDevStudioWindow *m_Window;
};

#endif // CDEVSTUDIOWINDOWMANAGER_H
