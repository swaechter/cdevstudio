#include "PluginProjects.h"

PluginProjects::PluginProjects()
{
	PluginPlatform *pluginplatform = PluginPlatform::getInstance();
	Window *window = pluginplatform->getWindowManager()->getWindow();
	
	m_ActionCreateProject = new QAction(tr("Create Project"), window);
	m_ActionLoadProject = new QAction(tr("Load Project"), window);
	m_ActionCloseProject = new QAction(tr("Close Project"), window);
	m_ActionProjectSettings = new QAction(tr("Project Settings"), window);
	
	window->getMenu(Project)->addAction(m_ActionCreateProject);
	window->getMenu(Project)->addAction(m_ActionLoadProject);
	window->getMenu(Project)->addAction(m_ActionCloseProject);
	window->getMenu(Settings)->addAction(m_ActionProjectSettings);
	
	connect(m_ActionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectCreateTrigger()));
	connect(m_ActionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectLoadTrigger()));
	connect(m_ActionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectCloseTrigger()));
	connect(m_ActionProjectSettings, SIGNAL(triggered(bool)), this, SLOT(actionProjectSettingsTrigger()));
}

PluginProjects::~PluginProjects()
{
}

QString PluginProjects::getName()
{
	return QString(tr("Projects"));
}

QString PluginProjects::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjects::getDescription()
{
	return QString(tr("PluginProjects provides some basic project templates"));
}

void PluginProjects::actionProjectCreateTrigger()
{
	QList<ProjectTemplate> templates;
	Window *window = PluginPlatform::getInstance()->getWindowManager()->getWindow();
	DialogCreateProject *dialog = new DialogCreateProject(templates, window);
	if(dialog->exec() == QDialog::Accepted)
	{
	}
}

void PluginProjects::actionProjectLoadTrigger()
{

}

void PluginProjects::actionProjectCloseTrigger()
{

}

void PluginProjects::actionProjectSettingsTrigger()
{

}
