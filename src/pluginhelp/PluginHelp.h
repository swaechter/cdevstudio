#ifndef PLUGINHELP_H
#define PLUGINHELP_H

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtCore/QObject>
#include <cdevstudioplatform/CDevStudioPlatformPlugin.h>
#include <cdevstudioplatform/ICDevStudioPlugin.h>

#include "PluginHelpExport.h"
#include "DialogHelp.h"
#include "DialogAbout.h"

class PLUGINHELP_API PluginHelp : public QObject, private ICDevStudioPlugin
{
	Q_OBJECT
	Q_INTERFACES(ICDevStudioPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.ICDevStudioPlugin")
	
public:
	PluginHelp();
	~PluginHelp();
	void init(CDevStudioPlatformPlugin *platformplugin);
	QString getPluginName();
	QString getPluginVersion();
	QString getPluginDescription();
	QStringList getPluginDependencies();
	
private:
	CDevStudioPlatformPlugin *dataPlatformPlugin;
	
private slots:
	void actionHelpTriggered();
	void actionAboutTriggered();
};

#endif // PLUGINHELP_H
