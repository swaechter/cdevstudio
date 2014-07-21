#include "PluginProjectExplorer.h"

PluginProjectExplorer::PluginProjectExplorer()
{
	IPlatform *platform = IPlatform::getInstance();
	Window *window = platform->getWindowManager()->getWindow();
	
	m_ActionProjectExplorer = new QAction(tr("Project Explorer"), window->menuBar());
	m_ActionProjectExplorer->setCheckable(true);
	m_ActionProjectExplorer->setChecked(true);
	window->getMenu(MenuView)->addAction(m_ActionProjectExplorer);
	
	m_ProjectExplorer = new ProjectExplorer(window);
	window->addDockWidget(Qt::LeftDockWidgetArea, m_ProjectExplorer);
	
	//connect(m_ProjectExplorer, SIGNAL(fileClicked(QString)), this, SLOT(fileOpen(QString)));
	connect(m_ActionProjectExplorer, SIGNAL(triggered(bool)), this, SLOT(actionProjectExplorerTriggered()));
	connect(platform->getProjectManager(), SIGNAL(projectOpened()), this, SLOT(projectOpen()));
	connect(platform->getProjectManager(), SIGNAL(projectClosed()), this, SLOT(projectClose()));
	
	Settings *settings = window->getSettingsDialog();
	PluginPage *pluginpage = new PluginPage(settings);
	settings->addSettingsPage(pluginpage);
}

PluginProjectExplorer::~PluginProjectExplorer()
{
}

void PluginProjectExplorer::actionProjectExplorerTriggered()
{
	if(m_ActionProjectExplorer->isChecked())
	{
		m_ProjectExplorer->show();
	}
	else
	{
		m_ProjectExplorer->hide();
	}
}

void PluginProjectExplorer::projectOpen()
{
	Project *project = IPlatform::getInstance()->getProjectManager()->getProject();
	m_ProjectExplorer->openView(project->getLocation());
}

void PluginProjectExplorer::projectClose()
{
	m_ProjectExplorer->clearView();
}

void PluginProjectExplorer::fileOpen(QString file)
{
	//if(!file.isEmpty())
	//{
	//	IPlatform::getInstance()->getProjectManager()->getProject()->addFile(file);
	//}
}
