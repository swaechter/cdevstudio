#include "CDevStudio.h"

CDevStudio::CDevStudio() : Window()
{
	initPlatform();
	initWindow();
	initStatusbar();
	initMenubar();
	initConnections();
	initWelcomeWidget();
	initPlugins();
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
	m_Platform->getWindowManager()->getWindow()->setMinimumSize(900, 600);
	m_Platform->getWindowManager()->getWindow()->setWindowTitle(tr("CDevStudio"));
}

void CDevStudio::initStatusbar()
{
	QStatusBar *statusbar = m_Platform->getWindowManager()->getWindow()->statusBar();
	statusbar->clearMessage();
}

void CDevStudio::initMenubar()
{
	QMenuBar *menubar = m_Platform->getWindowManager()->getWindow()->menuBar();
	
	m_MenuProject = new QMenu(tr("Project"), menubar);
	m_MenuSettings = new QMenu(tr("Settings"), menubar);
	m_MenuHelp = new QMenu(tr("Help"), menubar);
	m_ActionCreateProject = new QAction(tr("Create Project"), m_MenuProject);
	m_ActionLoadProject = new QAction(tr("Load Project"), m_MenuProject);
	m_ActionCloseProject = new QAction(tr("Close Project"), m_MenuProject);
	m_ActionExit = new QAction(tr("Exit"), m_MenuProject);
	m_ActionSettings = new QAction(tr("Settings"), m_MenuSettings);
	m_ActionPlugins = new QAction(tr("Plugins"), m_MenuSettings);
	m_ActionHelp = new QAction(tr("Help"), m_MenuHelp);
	m_ActionAbout = new QAction(tr("About"), m_MenuHelp);
	
	m_MenuProject->addAction(m_ActionCreateProject);
	m_MenuProject->addAction(m_ActionLoadProject);
	m_MenuProject->addAction(m_ActionCloseProject);
	m_MenuProject->addSeparator();
	m_MenuProject->addAction(m_ActionExit);
	m_MenuSettings->addAction(m_ActionSettings);
	m_MenuSettings->addAction(m_ActionPlugins);
	m_MenuHelp->addAction(m_ActionHelp);
	m_MenuHelp->addAction(m_ActionAbout);
	
	menubar->addMenu(m_MenuProject);
	menubar->addMenu(m_MenuSettings);
	menubar->addMenu(m_MenuHelp);
}

void CDevStudio::initConnections()
{
	connect(m_ActionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionCreateProjectTrigger()));
	connect(m_ActionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionLoadProjectTrigger()));
	connect(m_ActionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProjectTrigger()));
	connect(m_ActionExit, SIGNAL(triggered(bool)), this, SLOT(actionExitTrigger()));
	connect(m_ActionSettings, SIGNAL(triggered(bool)), this, SLOT(actionSettingsTrigger()));
	connect(m_ActionPlugins, SIGNAL(triggered(bool)), this, SLOT(actionPluginsTrigger()));
	connect(m_ActionHelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTrigger()));
	connect(m_ActionAbout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTrigger()));
}

void CDevStudio::initWelcomeWidget()
{
	QTextEdit *textedit = new QTextEdit(this);
	textedit->setText("Welcome to CDevStudio. This is an early alpha version");
	textedit->setReadOnly(true);
	setCentralWidget(textedit);
}

void CDevStudio::initPlugins()
{
	m_Platform->getPluginManager()->loadPlugins();
}

void CDevStudio::actionCreateProjectTrigger()
{
	if(m_Platform->getProjectManager()->getProject() == nullptr)
	{
		DialogCreateProject *dialog = new DialogCreateProject(m_Platform->getProjectManager()->getProjectTemplates(), this);
		if(dialog->exec() == QDialog::Accepted)
		{
			if(!dialog->getProjectName().isEmpty() && !dialog->getProjectDirectory().isEmpty() && !dialog->getProjectTemplate().isEmpty())
			{
				if(m_Platform->getProjectManager()->createProject(dialog->getProjectName(), dialog->getProjectDirectory(), dialog->getProjectTemplate()) != nullptr)
				{
				}
				else
				{
					QMessageBox::critical(this, tr("Error"), tr("Cannot create the project"));
				}
			}
			else
			{
				QMessageBox::critical(this, tr("Error"), tr("Project cannot be created because some important information are missing"));
			}
		}
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("Please close your current project before you create a new one"));
	}
}

void CDevStudio::actionLoadProjectTrigger()
{
	if(m_Platform->getProjectManager()->getProject() == nullptr)
	{
		QString projectfile = QFileDialog::getOpenFileName(this, tr("Select a project"), QDir::homePath(), "CDevStudio (*.cdev)");
		if(!projectfile.isEmpty())
		{
			if(m_Platform->getProjectManager()->loadProject(projectfile) != nullptr)
			{
			}
			else
			{
				QMessageBox::critical(this, tr("Error"), tr("Cannot load the project"));
			}
		}
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("Please close your current project before you load a new one"));
	}
}

void CDevStudio::actionCloseProjectTrigger()
{
	if(m_Platform->getProjectManager()->getProject() != nullptr)
	{
		m_Platform->getProjectManager()->closeProject();
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("There is no open project to close"));
	}
}

void CDevStudio::actionExitTrigger()
{
	exit(EXIT_SUCCESS);
}

void CDevStudio::actionSettingsTrigger()
{
 	DialogSettings *dialog = new DialogSettings(this);
	if(dialog->exec() == QDialog::Accepted)
	{
	}
}

void CDevStudio::actionPluginsTrigger()
{
	DialogPlugins *dialog = new DialogPlugins(m_Platform->getPluginManager()->getPlugins(), this);
	dialog->exec();
}

void CDevStudio::actionHelpTrigger()
{
	DialogHelp *dialog = new DialogHelp(this);
	dialog->exec();
}

void CDevStudio::actionAboutTrigger()
{
	DialogAbout *dialog = new DialogAbout(this);
	dialog->exec();
}
