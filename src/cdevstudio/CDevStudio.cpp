#include "CDevStudio.h"

CDevStudio::CDevStudio() : Window()
{
	initPlatform();
	preinitWindow();
	initSettings();
	loadPlugins();
	initWindow();
}

CDevStudio::~CDevStudio()
{
	delete m_Platform;
}

void CDevStudio::initPlatform()
{
	m_Platform = new Platform(this);
}

void CDevStudio::preinitWindow()
{
	Window *window = m_Platform->getWindowManager()->getWindow();
	
	m_ActionSettings = new QAction(tr("Settings"), window->menuBar());
	m_ActionPlugins = new QAction(tr("Plugins"), window->menuBar());
	m_ActionHelp = new QAction(tr("Help"), window->menuBar());
	m_ActionAbout = new QAction(tr("About"), window->menuBar());
	
	window->getMenu(MenuSettings)->addAction(m_ActionSettings);
	window->getMenu(MenuSettings)->addAction(m_ActionPlugins);
	window->getMenu(MenuHelp)->addAction(m_ActionHelp);
	window->getMenu(MenuHelp)->addAction(m_ActionAbout);
	
	connect(m_ActionSettings, SIGNAL(triggered(bool)), this, SLOT(actionSettingsTrigger()));
	connect(m_ActionPlugins, SIGNAL(triggered(bool)), this, SLOT(actionPluginsTrigger()));
	connect(m_ActionHelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTrigger()));
	connect(m_ActionAbout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTrigger()));
	
	setWindowTitle(tr("CDevStudio"));
	resize(1100, 700);
}

void CDevStudio::initSettings()
{
	Settings *settings = m_Platform->getWindowManager()->getWindow()->getSettingsDialog();
	GeneralPage *generalpage = new GeneralPage(settings);
	settings->addSettingsPage(generalpage);
}

void CDevStudio::loadPlugins()
{
	m_Platform->getPluginManager()->getPluginContainers();
}

void CDevStudio::initWindow()
{
	Window *window = m_Platform->getWindowManager()->getWindow();
	
	m_ActionExit = new QAction(tr("Exit"), window->menuBar());
	
	window->getMenu(MenuProject)->addAction(m_ActionExit);
	
	connect(m_ActionExit, SIGNAL(triggered(bool)), this, SLOT(actionExitTrigger()));
}
void CDevStudio::actionExitTrigger()
{
	exit(EXIT_SUCCESS);
}

void CDevStudio::actionSettingsTrigger()
{
	Settings *settings = m_Platform->getWindowManager()->getWindow()->getSettingsDialog();
	if(settings->exec() == QDialog::Accepted)
	{
	}
}

void CDevStudio::actionPluginsTrigger()
{
	DialogPlugins dialog(this, m_Platform->getPluginManager()->getPluginContainers());
	dialog.exec();
}

void CDevStudio::actionHelpTrigger()
{
	QString helptext = Backend::readFile(":/data/text_help.html");
	DialogHelp dialog(this, helptext);
	dialog.exec();
}

void CDevStudio::actionAboutTrigger()
{
	QString abouttext = Backend::readFile(":/data/text_about.html");
	QString licensetext = Backend::readFile(":/data/text_license.html");
	QString thankstotext = Backend::readFile(":/data/text_thanksto.html");
	DialogAbout dialog(this, abouttext, licensetext, thankstotext);
	dialog.exec();
}
