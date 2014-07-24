#include "PluginProjects.h"

PluginProjects::PluginProjects()
{
	IPlatform *platform = IPlatform::getInstance();
	Window *window = platform->getWindowManager()->getWindow();
	
	Settings *settings = window->getSettingsDialog();
	PluginPage *pluginpage = new PluginPage(settings);
	settings->addSettingsPage(pluginpage);
	
	m_ActionCreateProject = new QAction(tr("Create Project"), window->menuBar());
	m_ActionLoadProject = new QAction(tr("Load Project"), window->menuBar());
	m_ActionCloseProject = new QAction(tr("Close Project"), window->menuBar());
	m_ActionCreateFile = new QAction(tr("Create File"), window->menuBar());
	m_ActionDeleteFile = new QAction(tr("Delete File"), window->menuBar());
	m_ActionRenameFile = new QAction(tr("Rename File"), window->menuBar());
	m_ActionSaveFile = new QAction(tr("Save File"), window->menuBar());
	m_ActionCloseFile = new QAction(tr("Close File"), window->menuBar());
	
	window->getMenu(MenuProject)->addAction(m_ActionCreateProject);
	window->getMenu(MenuProject)->addAction(m_ActionLoadProject);
	window->getMenu(MenuProject)->addAction(m_ActionCloseProject);
	window->getMenu(MenuFile)->addAction(m_ActionCreateFile);
	window->getMenu(MenuFile)->addAction(m_ActionDeleteFile);
	window->getMenu(MenuFile)->addAction(m_ActionRenameFile);
	window->getMenu(MenuFile)->addSeparator();
	window->getMenu(MenuFile)->addAction(m_ActionSaveFile);
	window->getMenu(MenuFile)->addSeparator();
	window->getMenu(MenuFile)->addAction(m_ActionCloseFile);
	
	connect(m_ActionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProjectTrigger()));
	connect(m_ActionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionLoadProjectTrigger()));
	connect(m_ActionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProjectTrigger()));
	connect(m_ActionCreateFile, SIGNAL(triggered(bool)), this, SLOT(actionCreateFileTrigger()));
	connect(m_ActionDeleteFile, SIGNAL(triggered(bool)), this, SLOT(actionDeleteFileTrigger()));
	connect(m_ActionRenameFile, SIGNAL(triggered(bool)), this, SLOT(actionRenameFileTrigger()));
	connect(m_ActionSaveFile, SIGNAL(triggered(bool)), this, SLOT(actionSaveFileTrigger()));
	connect(m_ActionCloseFile, SIGNAL(triggered(bool)), this, SLOT(actionCloseFileTrigger()));
}

PluginProjects::~PluginProjects()
{
}

void PluginProjects::actionCreateProjectTrigger()
{
	if(!IPlatform::getInstance()->getProjectManager()->getProject())
	{
		QList<ProjectTemplate> templates;
		templates.append(ProjectTemplate(tr("Empty Project"), tr("An empty project"), QStringList()));
		templates.append(ProjectTemplate(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c"));
		templates.append(ProjectTemplate(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp"));
		
		IPlatform *platform = IPlatform::getInstance();
		CreateProjectDialog *dialog = new CreateProjectDialog(templates, platform->getWindowManager()->getWindow());
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

void PluginProjects::actionLoadProjectTrigger()
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

void PluginProjects::actionCloseProjectTrigger()
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

void PluginProjects::actionCreateFileTrigger()
{
}

void PluginProjects::actionDeleteFileTrigger()
{
}

void PluginProjects::actionRenameFileTrigger()
{
}

void PluginProjects::actionSaveFileTrigger()
{
}

void PluginProjects::actionCloseFileTrigger()
{
}
