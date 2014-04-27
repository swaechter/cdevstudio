#ifndef PLATFORM_H
#define PLATFORM_H

#include <QtCore/QList>
#include <QtCore/QDebug>

#include "PlatformExport.h"
#include "WindowManager.h"
#include "PluginManager.h"
#include "ProjectManager.h"
#include "interfaces/IPlatform.h"

class CDEVSTUDIOPLATFORM_EXPORT Platform : public IPlatform
{
	Q_OBJECT
	
public:
	Platform(Window *window);
	~Platform();
	virtual WindowManager *getWindowManager();
	virtual PluginManager *getPluginManager();
	virtual ProjectManager *getProjectManager();
	
private:
	WindowManager *m_WindowManager;
	PluginManager *m_PluginManager;
	ProjectManager *m_ProjectManager;
};

#endif // PLATFORM_H
