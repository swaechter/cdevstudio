#include "Window.h"

Window::Window() : QMainWindow()
{
	initWindow();
	initMenues();
}

Window::~Window()
{
}

QMenu *Window::getMenu(MenuTypes type)
{
	switch(type)
	{
		case MenuProject:
		{
			return m_MenuProject;
		}
		case MenuView:
		{
			return m_MenuView;
		}
		case MenuSettings:
		{
			return m_MenuSettings;
		}
		case MenuHelp:
		{
			return m_MenuHelp;
		}
	}
	return nullptr;
}

Settings *Window::getSettingsDialog()
{
	return m_Settings;
}

QTabWidget *Window::getTabWidget()
{
	return m_TabWidget;
}

void Window::initWindow()
{
	m_TabWidget = new QTabWidget(this);
	m_TabWidget->setTabsClosable(true);
	setCentralWidget(m_TabWidget);
	
	connect(m_TabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}

void Window::initMenues()
{
	m_MenuProject = new QMenu(tr("Project"), this);
	m_MenuView = new QMenu(tr("View"), this);
	m_MenuSettings = new QMenu(tr("Settings"), this);
	m_MenuHelp = new QMenu(tr("Help"), this);
	
	menuBar()->addMenu(m_MenuProject);
	menuBar()->addMenu(m_MenuView);
	menuBar()->addMenu(m_MenuSettings);
	menuBar()->addMenu(m_MenuHelp);
	
	m_Settings = new Settings(this);
	m_Settings->hide();
}

void Window::closeTab(int index)
{
	if(index >= 0)
	{
		emit closeTabRequested(m_TabWidget->tabText(index));
	}
}
