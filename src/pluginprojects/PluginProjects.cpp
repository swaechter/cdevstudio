#include "PluginProjects.h"

PluginProjects::PluginProjects()
{
	IPlatform *platform = IPlatform::getInstance();
	Window *window = platform->getWindowManager()->getWindow();
	
	m_ActionCreateProject = new QAction(tr("Create Project"), window);
	m_ActionLoadProject = new QAction(tr("Load Project"), window);
	m_ActionCloseProject = new QAction(tr("Close Project"), window);
	m_ActionProjectSettings = new QAction(tr("Project Settings"), window);
	
	window->getMenu(MenuProject)->addAction(m_ActionCreateProject);
	window->getMenu(MenuProject)->addAction(m_ActionLoadProject);
	window->getMenu(MenuProject)->addAction(m_ActionCloseProject);
	window->getMenu(MenuSettings)->addAction(m_ActionProjectSettings);
	
	connect(m_ActionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectCreateTrigger()));
	connect(m_ActionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectLoadTrigger()));
	connect(m_ActionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectCloseTrigger()));
	connect(m_ActionProjectSettings, SIGNAL(triggered(bool)), this, SLOT(actionProjectSettingsTrigger()));
}

PluginProjects::~PluginProjects()
{
}

void PluginProjects::actionProjectCreateTrigger()
{
	QList<ProjectTemplate> templates;
	templates.append(ProjectTemplate(tr("Empty Project"), tr("An empty project"), QStringList()));
	templates.append(ProjectTemplate(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c"));
	templates.append(ProjectTemplate(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp"));
	
	IPlatform *platform = IPlatform::getInstance();
	DialogCreateProject *dialog = new DialogCreateProject(templates, platform->getWindowManager()->getWindow());
	if(dialog->exec() == QDialog::Accepted)
	{
		if(!dialog->getProjectName().isEmpty() && !dialog->getProjectName().isEmpty() && !dialog->getProjectLocation().isEmpty())
		{
			foreach(ProjectTemplate projecttemplate, templates)
			{
				if(projecttemplate.getName().compare(dialog->getTemplateName()) == 0)
				{
					if(platform->getProjectManager()->createProject(dialog->getProjectName(), dialog->getProjectLocation(), projecttemplate.getFiles()))
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
	QString projectfile = QFileDialog::getOpenFileName(IPlatform::getInstance()->getWindowManager()->getWindow(), tr("Load project"), QDir::homePath(), tr("Project (*.cdev)"));
	if(!projectfile.isEmpty())
	{
		if(IPlatform::getInstance()->getProjectManager()->loadProject(projectfile))
		{
		}
	}
}

void PluginProjects::actionProjectCloseTrigger()
{
	IPlatform::getInstance()->getProjectManager()->closeProject();
}

void PluginProjects::actionProjectSettingsTrigger()
{

}
