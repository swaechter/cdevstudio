#include "CDevStudio.h"

CDevStudio::CDevStudio() : Window()
{
	initPlatform();
	initWindow();
	loadPlugins();
}

CDevStudio::~CDevStudio()
{
	delete m_Platform;
}

void CDevStudio::initPlatform()
{
	m_Platform = new Platform(this);
}

void CDevStudio::initWindow()
{
	Window *window = m_Platform->getWindowManager()->getWindow();
	
	//m_ActionExit = new QAction(tr("Exit"), window->menuBar());
	m_ActionSettings = new QAction(tr("Settings"), window->menuBar());
	m_ActionPlugins = new QAction(tr("Plugins"), window->menuBar());
	m_ActionHelp = new QAction(tr("Help"), window->menuBar());
	m_ActionAbout = new QAction(tr("About"), window->menuBar());
	
	//window->getMenu(MenuProject)->addAction(m_ActionExit);
	window->getMenu(MenuSettings)->addAction(m_ActionSettings);
	window->getMenu(MenuSettings)->addAction(m_ActionPlugins);
	window->getMenu(MenuHelp)->addAction(m_ActionHelp);
	window->getMenu(MenuHelp)->addAction(m_ActionAbout);
	
	//connect(m_ActionExit, SIGNAL(triggered(bool)), this, SLOT(actionExitTrigger()));
	connect(m_ActionSettings, SIGNAL(triggered(bool)), this, SLOT(actionSettingsTrigger()));
	connect(m_ActionPlugins, SIGNAL(triggered(bool)), this, SLOT(actionPluginsTrigger()));
	connect(m_ActionHelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTrigger()));
	connect(m_ActionAbout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTrigger()));
	
	setWindowTitle(tr("CDevStudio"));
	resize(1100, 700);
}

void CDevStudio::loadPlugins()
{
	m_Platform->getPluginManager()->getPluginContainers();
}

void CDevStudio::actionExitTrigger()
{
	// TODO Create a possibility to prepend and append QActions to a QMenu
}

void CDevStudio::actionSettingsTrigger()
{

}

void CDevStudio::actionPluginsTrigger()
{

}

void CDevStudio::actionHelpTrigger()
{

}

void CDevStudio::actionAboutTrigger()
{

}
