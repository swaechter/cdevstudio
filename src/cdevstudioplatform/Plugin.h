#ifndef PLUGIN_H
#define PLUGIN_H

#include <QtCore/QObject>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT Plugin : public QObject
{
	Q_OBJECT
	
public:
	Plugin();
	virtual ~Plugin();
	virtual QString getName() = 0;
	virtual QString getVersion() = 0;
	virtual QString getDescription() = 0;
};

Q_DECLARE_INTERFACE(Plugin, "ch.swaechter.cdevstudio.Plugin")

#endif // PLUGIN_H
