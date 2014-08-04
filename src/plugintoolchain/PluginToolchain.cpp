#include "PluginToolchain.h"

PluginToolchain::PluginToolchain()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindowManager()->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
	
	m_ActionBuild = new QAction(tr("Build"), window->menuBar());
	m_ActionRun = new QAction(tr("Run"), window->menuBar());
	m_ActionBuildAndRun = new QAction(tr("Build & Run"), window->menuBar());
	
	m_ActionBuild->setShortcut(Qt::Key_F5);
	m_ActionRun->setShortcut(Qt::Key_F6);
	m_ActionBuildAndRun->setShortcut(Qt::Key_F7);
	
	window->getMenu(MenuCode)->addAction(m_ActionBuild);
	window->getMenu(MenuCode)->addAction(m_ActionRun);
	window->getMenu(MenuCode)->addAction(m_ActionBuildAndRun);
	
	connect(m_ActionBuild, SIGNAL(triggered(bool)), this, SLOT(actionBuildTrigger()));
	connect(m_ActionRun, SIGNAL(triggered(bool)), this, SLOT(actionRunTrigger()));
	connect(m_ActionBuildAndRun, SIGNAL(triggered(bool)), this, SLOT(actionBuldAndRunTrigger()));
}

PluginToolchain::~PluginToolchain()
{
}

void PluginToolchain::actionBuildTrigger()
{

}

void PluginToolchain::actionRunTrigger()
{

}

void PluginToolchain::actionBuldAndRunTrigger()
{

}
