#ifndef PLUGINHELP_H
#define PLUGINHELP_H

#include <QtWidgets/QAction>
#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPluginManager.h>
#include <cdevstudioplatform/IPlugin.h>
#include <plugincore/PluginCore.h>

#include "PluginHelpExport.h"

#include <QtCore/QDebug>

class PLUGINHELP_EXPORT PluginHelp : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginHelp();
	~PluginHelp();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	PluginCore *m_PluginCore;
	QAction *m_Help;
	QAction *m_About;
	
private slots:
	void actionHelp();
	void actionAbout();
};

#endif // PLUGINHELP_H
