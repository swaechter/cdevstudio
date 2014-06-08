#include "PluginProjectExplorer.h"

PluginProjectExplorer::PluginProjectExplorer()
{
	PluginPlatform *pluginplatform = PluginPlatform::getInstance();
	Window *window = pluginplatform->getWindowManager()->getWindow();
	
	m_ActionProjectExplorer = new QAction(tr("Project Explorer"), window);
	m_ActionProjectExplorer->setCheckable(true);
	m_ActionProjectExplorer->setChecked(true);
	window->getMenu(MenuView)->addAction(m_ActionProjectExplorer);
	
	m_ProjectExplorer = new ProjectExplorer(window);
	window->addDockWidget(Qt::LeftDockWidgetArea, m_ProjectExplorer);
	
	connect(m_ProjectExplorer, SIGNAL(fileClicked(QString)), this, SLOT(fileOpen(QString)));
	connect(m_ActionProjectExplorer, SIGNAL(triggered(bool)), this, SLOT(actionProjectExplorerTriggered()));
	connect(pluginplatform->getProjectManager(), SIGNAL(projectOpened()), this, SLOT(projectOpen()));
	connect(pluginplatform->getProjectManager(), SIGNAL(projectClosed()), this, SLOT(projectClose()));
}

PluginProjectExplorer::~PluginProjectExplorer()
{
}

QString PluginProjectExplorer::getName()
{
	return QString(tr("ProjectExplorer"));
}

QString PluginProjectExplorer::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjectExplorer::getDescription()
{
	return QString(tr("PluginProjectExplorer provides a basic project view"));
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
	Project *project = PluginPlatform::getInstance()->getProjectManager()->getProject();
	m_ProjectExplorer->openView(project->getLocation());
}

void PluginProjectExplorer::projectClose()
{
	m_ProjectExplorer->clearView();
}

void PluginProjectExplorer::fileOpen(QString file)
{
	if(!file.isEmpty())
	{
		PluginPlatform::getInstance()->getProjectManager()->getProject()->addFile(file);
	}
}
