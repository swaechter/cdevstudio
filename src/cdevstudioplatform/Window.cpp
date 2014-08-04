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
		case MenuFile:
		{
			return m_MenuFile;
		}
		case MenuCode:
		{
			return m_MenuCode;
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

TabWidget *Window::getTabWidget()
{
	return m_TabWidget;
}

Settings *Window::getSettingsDialog()
{
	return m_Settings;
}

void Window::initWindow()
{
	m_TabWidget = new TabWidget(this);
	setCentralWidget(m_TabWidget);
}

void Window::initMenues()
{
	m_MenuProject = new QMenu(tr("Project"), menuBar());
	m_MenuFile = new QMenu(tr("File"), menuBar());
	m_MenuCode = new QMenu(tr("Code"), menuBar());
	m_MenuView = new QMenu(tr("View"), menuBar());
	m_MenuSettings = new QMenu(tr("Settings"), menuBar());
	m_MenuHelp = new QMenu(tr("Help"), menuBar());
	
	menuBar()->addMenu(m_MenuProject);
	menuBar()->addMenu(m_MenuFile);
	menuBar()->addMenu(m_MenuCode);
	menuBar()->addMenu(m_MenuView);
	menuBar()->addMenu(m_MenuSettings);
	menuBar()->addMenu(m_MenuHelp);
	
	m_Settings = new Settings(this);
	m_Settings->hide();
}
