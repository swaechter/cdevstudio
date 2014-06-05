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
	templates.append(ProjectTemplate(tr("Empty Project"), tr("An empty project"), QStringList()));
	templates.append(ProjectTemplate(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c"));
	templates.append(ProjectTemplate(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp"));
	
	PluginPlatform *pluginplatform = PluginPlatform::getInstance();
	DialogCreateProject *dialog = new DialogCreateProject(templates, pluginplatform->getWindowManager()->getWindow());
	if(dialog->exec() == QDialog::Accepted)
	{
		if(!dialog->getProjectName().isEmpty() && !dialog->getProjectName().isEmpty() && !dialog->getProjectLocation().isEmpty())
		{
			foreach(ProjectTemplate projecttemplate, templates)
			{
				if(projecttemplate.getName().compare(dialog->getTemplateName()) == 0)
				{
					if(pluginplatform->getProjectManager()->createProject(dialog->getProjectName(), dialog->getProjectLocation(), projecttemplate.getFiles()))
					{
					}
					break;
				}
			}
		}
	}
}

void PluginProjects::actionProjectLoadTrigger()
{
	QString projectfile = QFileDialog::getOpenFileName(PluginPlatform::getInstance()->getWindowManager()->getWindow(), tr("Load project"), QDir::homePath(), tr("Project (*.cdev)"));
	if(!projectfile.isEmpty())
	{
		if(PluginPlatform::getInstance()->getProjectManager()->loadProject(projectfile))
		{
		}
	}
}

void PluginProjects::actionProjectCloseTrigger()
{
	PluginPlatform::getInstance()->getProjectManager()->closeProject();
}

void PluginProjects::actionProjectSettingsTrigger()
{

}
