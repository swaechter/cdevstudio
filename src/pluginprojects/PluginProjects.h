#ifndef PLUGINPROJECTS_H
#define PLUGINPROJECTS_H

#include <QtWidgets/QAction>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QObject>
#include <cdevstudioplatform/PluginPlatform.h>
#include <cdevstudioplatform/Plugin.h>
#include <cdevstudioplatform/WindowManager.h>
#include <cdevstudioplatform/Window.h>

#include "PluginProjectsExport.h"
#include "ProjectTemplate.h"
#include "DialogCreateProject.h"

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
	
private:
	QAction *m_ActionCreateProject;
	QAction *m_ActionLoadProject;
	QAction *m_ActionCloseProject;
	QAction *m_ActionProjectSettings;
	
private slots:
	void actionProjectCreateTrigger();
	void actionProjectLoadTrigger();
	void actionProjectCloseTrigger();
	void actionProjectSettingsTrigger();
};

#endif // PLUGINPROJECTS_H
