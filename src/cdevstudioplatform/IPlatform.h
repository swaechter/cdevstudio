#ifndef IPLATFORM
#define IPLATFORM

#include <QtCore/QObject>

#include "IPluginManager.h"

class CDEVSTUDIOPLATFORM_EXPORT IPlatform : public QObject
{
	Q_OBJECT
	
public:
	~IPlatform();
	static IPlatform *getInstance();
	virtual IPluginManager *getPluginManager() = 0;
	
protected:
	IPlatform(QObject *parent);
	static IPlatform *m_IPlatform;
};

#endif // IPLATFORM
