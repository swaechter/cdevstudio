#ifndef PLATFORM_H
#define PLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "PlatformExport.h"
#include "IPlatform.h"
#include "PluginManager.h"
#include "ProjectManager.h"
#include "WindowManager.h"
#include "Window.h"

class CDEVSTUDIOPLATFORM_EXPORT Platform : public IPlatform
{
	Q_OBJECT
	
public:
	Platform(Window *window);
	PluginManager *getPluginManager();
	ProjectManager *getProjectManager();
        WindowManager *getWindowManager();
	
private:
	PluginManager *m_PluginManager;
	ProjectManager *m_ProjectManager;
        WindowManager *m_WindowManager;
};

#endif // PLATFORM_H
