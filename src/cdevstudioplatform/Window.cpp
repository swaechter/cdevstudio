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
		case Project:
		{
			return m_MenuProject;
		}
		case View:
		{
			return m_MenuView;
		}
		case Settings:
		{
			return m_MenuSettings;
		}
		case Help:
		{
			return m_MenuHelp;
		}
	}
	return nullptr;
}

void Window::initWindow()
{
	QTabWidget *tabwidget = new QTabWidget(this);
	setCentralWidget(tabwidget);
	
	QTextEdit *textedit = new QTextEdit(tabwidget);
	tabwidget->addTab(textedit, "Welcome");
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
