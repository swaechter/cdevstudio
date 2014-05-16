#ifndef PLUGINSETTINGS_H
#define PLUGINSETTINGS_H

#include <QtWidgets/QAction>
#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPluginManager.h>
#include <cdevstudioplatform/IPlugin.h>
#include <plugincore/PluginCore.h>

#include "PluginSettingsExport.h"
#include "DialogSettings.h"

#include <QtCore/QDebug>

class PLUGINSETTINGS_EXPORT PluginSettings : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginSettings();
	~PluginSettings();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	PluginCore *m_PluginCore;
	QAction *m_Settings;
	
private slots:
	void actionSettings();
};

#endif // PLUGINSETTINGS_H
