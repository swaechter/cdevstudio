#ifndef IPLUGIN_H
#define IPLUGIN_H

#include <QtCore/QObject>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT IPlugin : public QObject
{
	Q_OBJECT
	
public:
	IPlugin();
	virtual ~IPlugin();
	virtual QString getName() = 0;
	virtual QString getVersion() = 0;
	virtual QString getDescription() = 0;
};

Q_DECLARE_INTERFACE(IPlugin, "ch.swaechter.cdevstudio.IPlugin")

#endif // IPLUGIN_H
