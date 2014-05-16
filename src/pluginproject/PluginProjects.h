#ifndef PLUGINPROJECTS_H
#define PLUGINPROJECTS_H

#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPluginManager.h>
#include <cdevstudioplatform/IPlugin.h>
#include <plugincore/PluginCore.h>

#include "PluginProjectsExport.h"
#include "ProjectTemplate.h"
#include "Project.h"

#include <QtCore/QDebug>

class PLUGINPROJECTS_EXPORT PluginProjects : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginProjects();
	~PluginProjects();
	QString getName();
	QString getVersion();
	QString getDescription();
	void addTemplate(QString name, QString description, QStringList files);
	QList<ProjectTemplate> getTemplates();
	
private:
	PluginCore *m_PluginCore;
	QList<ProjectTemplate> m_Templates;
};

#endif // PLUGINPROJECTS_H
