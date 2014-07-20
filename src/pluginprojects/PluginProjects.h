#ifndef PLUGINPROJECTS_H
#define PLUGINPROJECTS_H

#include <QtWidgets/QAction>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPlugin.h>
#include <cdevstudioplatform/WindowManager.h>
#include <cdevstudioplatform/Window.h>

#include "PluginProjectsExport.h"
#include "ProjectTemplate.h"
#include "DialogCreateProject.h"

class PLUGINPROJECTS_EXPORT PluginProjects : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin" FILE "PluginProjects.json")
	
public:
	PluginProjects();
	~PluginProjects();
	
private:
	QAction *m_ActionCreateProject;
	QAction *m_ActionLoadProject;
	QAction *m_ActionCloseProject;
	
private slots:
	void actionProjectCreateTrigger();
	void actionProjectLoadTrigger();
	void actionProjectCloseTrigger();
};

#endif // PLUGINPROJECTS_H
