#ifndef PLATFORM_H
#define PLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "PlatformExport.h"
#include "IPlatform.h"
#include "IPluginManager.h"

class CDEVSTUDIOPLATFORM_EXPORT Platform : public IPlatform
{
	Q_OBJECT
	
public:
	Platform(QObject *parent);
	~Platform();
	IPluginManager *getPluginManager();
	
private:
	IPluginManager *m_PluginManager;
};

#endif // PLATFORM_H
