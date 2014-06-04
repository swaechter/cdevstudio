#ifndef PLATFORM_H
#define PLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "PlatformExport.h"
#include "PluginPlatform.h"
#include "PluginManager.h"
#include "ProjectManager.h"

class CDEVSTUDIOPLATFORM_EXPORT Platform : public PluginPlatform
{
	Q_OBJECT
	
public:
	Platform(QObject *parent);
	~Platform();
	PluginManager *getPluginManager();
	ProjectManager *getProjectManager();
	
private:
	PluginManager *m_PluginManager;
	ProjectManager *m_ProjectManager;
};

#endif // PLATFORM_H
