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
#include "PluginPage.h"
#include "CreateProjectDialog.h"

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
	QAction *m_ActionCreateFile;
	QAction *m_ActionDeleteFile;
	QAction *m_ActionRenameFile;
	QAction *m_ActionSaveFile;
	QAction *m_ActionCloseFile;
	
private slots:
	void actionCreateProjectTrigger();
	void actionLoadProjectTrigger();
	void actionCloseProjectTrigger();
	void actionCreateFileTrigger();
	void actionDeleteFileTrigger();
	void actionRenameFileTrigger();
	void actionSaveFileTrigger();
	void actionCloseFileTrigger();
};

#endif // PLUGINPROJECTS_H
