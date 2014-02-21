#ifndef ICDEVSTUDIOPLUGIN_H
#define ICDEVSTUDIOPLUGIN_H

#include <QtCore/QString>
#include <QtCore/QStringList>

class ICDevStudioPlugin
{
public:
	virtual ~ICDevStudioPlugin() {}
	virtual QString getPluginName() = 0;
	virtual QString getPluginVersion() = 0;
	virtual QString getPluginDescription() = 0;
	virtual QStringList getPluginDependencies() = 0;
};

Q_DECLARE_INTERFACE(ICDevStudioPlugin, "ch.swaechter.cdevstudioplatform.ICDevStudioPlugin/1.0");

#endif // ICDEVSTUDIOPLUGIN_H
