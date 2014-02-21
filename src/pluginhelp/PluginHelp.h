#ifndef PLUGINHELP_H
#define PLUGINHELP_H

#include <QtCore/QObject>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QGridLayout>
#include <cdevstudioplatform/ICDevStudioPlugin.h>
#include <cdevstudioplatform/CDevStudioPlatform.h>
#include <cdevstudioplatform/CDevStudioMenuBar.h>
#include <cdevstudioplatform/CDevStudioMenu.h>
#include <cdevstudioplatform/CDevStudioAction.h>
#include <cdevstudioplatform/CDevStudioBackend.h>

#include "PluginHelpExport.h"

class PLUGINHELP_API PluginHelp : public QObject, private ICDevStudioPlugin
{
	Q_OBJECT
	Q_INTERFACES(ICDevStudioPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.ICDevStudioPlugin" FILE "PluginHelp.json")
	
public:
	PluginHelp();
	~PluginHelp();
	QString getPluginName();
	QString getPluginVersion();
	QString getPluginDescription();
	QStringList getPluginDependencies();
	
private slots:
	void actionHelpTriggered();
	void actionAboutTriggered();
};

#endif // PLUGINHELP_H
