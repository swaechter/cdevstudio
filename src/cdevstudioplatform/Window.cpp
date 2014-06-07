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

QTabWidget *Window::getTabWidget()
{
	return m_TabWidget;
}

void Window::initWindow()
{
	m_TabWidget = new QTabWidget(this);
	setCentralWidget(m_TabWidget);
	
	QTextEdit *textedit = new QTextEdit(m_TabWidget);
	m_TabWidget->addTab(textedit, "Welcome");
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
}
