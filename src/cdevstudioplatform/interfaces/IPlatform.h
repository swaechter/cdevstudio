#ifndef IPLATFORM
#define IPLATFORM

#include <QtCore/QObject>
#include <QtCore/QDebug>

#include "../WindowManager.h"
#include "../PluginManager.h"
#include "../ProjectManager.h"

class IPlatform : public QObject
{
	Q_OBJECT
	
public:
	virtual ~IPlatform();
	static IPlatform *getInstance();
	virtual WindowManager *getWindowManager() = 0;
	virtual PluginManager *getPluginManager() = 0;
	virtual ProjectManager *getProjectManager() = 0;
	
protected:
	IPlatform(QObject *parent);
	static IPlatform *m_IPlatform;
};

#endif // IPLATFORM
