#ifndef CDEVSTUDIOPLUGINMANAGER_H
#define CDEVSTUDIOPLUGINMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioPlatformPlugin.h"
#include "CDevStudioBackend.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPluginManager : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioPluginManager();
	~CDevStudioPluginManager();
	void initPlugins(CDevStudioPlatformPlugin *platformplugin);
	QList<ICDevStudioPlugin *> getPlugins();
	
private:
	QList<ICDevStudioPlugin *> m_Plugins;
	CDevStudioBackend m_Backend;
};

#endif // CDEVSTUDIOPLUGINMANAGER_H
