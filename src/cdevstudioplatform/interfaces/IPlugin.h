#ifndef IPLUGIN_H
#define IPLUGIN_H

#include <QtCore/QString>
#include <QtCore/QStringList>

class IPlugin
{
public:
	virtual ~IPlugin() {}
	virtual QString getName() = 0;
	virtual QString getVersion() = 0;
	virtual QString getDescription() = 0;
};

Q_DECLARE_INTERFACE(IPlugin, "ch.swaechter.cdevstudioplatform.IPlugin/1.0");

#endif // IPLUGIN_H
