#ifndef PLUGINPLATFORM
#define PLUGINPLATFORM

#include <QtCore/QObject>

#include "PluginManager.h"
#include "ProjectManager.h"
#include "WindowManager.h"

class CDEVSTUDIOPLATFORM_EXPORT PluginPlatform : public QObject
{
	Q_OBJECT
	
public:
	static PluginPlatform *getInstance();
	virtual PluginManager *getPluginManager() = 0;
	virtual ProjectManager *getProjectManager() = 0;
        virtual WindowManager *getWindowManager() = 0;
	
protected:
	PluginPlatform(QObject *parent);
	static PluginPlatform *m_PluginPlatform;
};

#endif // PLUGINPLATFORM
