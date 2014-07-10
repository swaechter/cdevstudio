#ifndef IPLATFORM_H
#define IPLATFORM_H

#include <QtCore/QObject>

#include "PluginManager.h"
#include "ProjectManager.h"
#include "WindowManager.h"

class CDEVSTUDIOPLATFORM_EXPORT IPlatform : public QObject
{
	Q_OBJECT
	
public:
	static IPlatform *getInstance();
	virtual PluginManager *getPluginManager() = 0;
	virtual ProjectManager *getProjectManager() = 0;
        virtual WindowManager *getWindowManager() = 0;
	
protected:
	IPlatform(QObject *parent);
	static IPlatform *m_IPlatform;
};

#endif // IPLATFORM_H
