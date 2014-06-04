#ifndef PLUGINPROJECTS_H
#define PLUGINPROJECTS_H

#include <QtCore/QObject>
#include <cdevstudioplatform/PluginPlatform.h>
#include <cdevstudioplatform/PluginManager.h>
#include <cdevstudioplatform/Plugin.h>

#include "PluginProjectsExport.h"
#include "ProjectTemplate.h"

#include <QtCore/QDebug>

class PLUGINPROJECTS_EXPORT PluginProjects : public Plugin
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.Plugin")
	
public:
	PluginProjects();
	~PluginProjects();
	QString getName();
	QString getVersion();
	QString getDescription();
	void addTemplate(QString name, QString description, QStringList files);
	QList<ProjectTemplate> getTemplates();
	
private:
	QList<ProjectTemplate> m_Templates;
};

#endif // PLUGINPROJECTS_H
