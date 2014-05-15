#include "Window.h"

Window::Window() : QMainWindow()
{
	QStackedWidget *stackedwidget = new QStackedWidget(this);
	QTextEdit *textedit = new QTextEdit(stackedwidget);
	stackedwidget->addWidget(textedit);
	
	m_MenuProject = new QMenu(tr("Project"), menuBar());
	m_MenuSettings = new QMenu(tr("Settings"), menuBar());
	m_MenuHelp = new QMenu(tr("Help"), menuBar());
	
	menuBar()->addMenu(m_MenuProject);
	menuBar()->addMenu(m_MenuSettings);
	menuBar()->addMenu(m_MenuHelp);
	
	setCentralWidget(stackedwidget);
	setMinimumSize(800, 500);
	setWindowTitle(tr("CDevStudio"));
}

Window::~Window()
{
}

QMenu *Window::getProjectMenu()
{
	return m_MenuProject;
}

QMenu *Window::getSettingsMenu()
{
	return m_MenuSettings;
}

QMenu *Window::getHelpMenu()
{
	return m_MenuHelp;
}
