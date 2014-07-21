#include "PluginProjects.h"

PluginProjects::PluginProjects()
{
	IPlatform *platform = IPlatform::getInstance();
	Window *window = platform->getWindowManager()->getWindow();
	
	m_ActionCreateProject = new QAction(tr("Create Project"), window->menuBar());
	m_ActionLoadProject = new QAction(tr("Load Project"), window->menuBar());
	m_ActionCloseProject = new QAction(tr("Close Project"), window->menuBar());
	
	window->getMenu(MenuProject)->addAction(m_ActionCreateProject);
	window->getMenu(MenuProject)->addAction(m_ActionLoadProject);
	window->getMenu(MenuProject)->addAction(m_ActionCloseProject);
	
	connect(m_ActionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectCreateTrigger()));
	connect(m_ActionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectLoadTrigger()));
	connect(m_ActionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionProjectCloseTrigger()));
	
	Settings *settings = window->getSettingsDialog();
	PluginPage *pluginpage = new PluginPage(settings);
	settings->addSettingsPage(pluginpage);
}

PluginProjects::~PluginProjects()
{
}

void PluginProjects::actionProjectCreateTrigger()
{
	if(!IPlatform::getInstance()->getProjectManager()->getProject())
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
	else
	{
		QMessageBox::information(IPlatform::getInstance()->getWindowManager()->getWindow(), tr("Information"), tr("Please close the current project before you create a new one."));
	}
}

void PluginProjects::actionProjectLoadTrigger()
{
	if(!IPlatform::getInstance()->getProjectManager()->getProject())
	{
		QString projectfile = QFileDialog::getOpenFileName(IPlatform::getInstance()->getWindowManager()->getWindow(), tr("Load project"), QDir::homePath(), tr("Project (*.cdev)"));
		if(!projectfile.isEmpty())
		{
			if(IPlatform::getInstance()->getProjectManager()->loadProject(projectfile))
			{
			}
		}
	}
	else
	{
		QMessageBox::information(IPlatform::getInstance()->getWindowManager()->getWindow(), tr("Information"), tr("Please close the current project before you open a new one."));
	}
}

void PluginProjects::actionProjectCloseTrigger()
{
	if(IPlatform::getInstance()->getProjectManager()->getProject())
	{
		IPlatform::getInstance()->getProjectManager()->closeProject();
	}
	else
	{
		QMessageBox::information(IPlatform::getInstance()->getWindowManager()->getWindow(), tr("Information"), tr("There is no active project to close."));
	}
}
