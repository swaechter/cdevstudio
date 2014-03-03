#include "CDevStudio.h"

CDevStudio::CDevStudio() : CDevStudioWindow()
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
	delete cdevstudioPlatform;
}

void CDevStudio::initPlatform()
{
	cdevstudioPlatform = new CDevStudioPlatform(this);
}

void CDevStudio::initWindow()
{
	cdevstudioPlatform->getWindow()->setMinimumSize(900, 600);
	cdevstudioPlatform->getWindow()->setWindowTitle(tr("CDevStudio"));
}

void CDevStudio::initStatusbar()
{
	QStatusBar *statusbar = cdevstudioPlatform->getWindow()->statusBar();
	statusbar->clearMessage();
}

void CDevStudio::initMenubar()
{
	QMenuBar *menubar = cdevstudioPlatform->getWindow()->menuBar();
	
	menuProject = new QMenu(tr("Project"), menubar);
	menuSettings = new QMenu(tr("Settings"), menubar);
	actionCreateProject = new QAction(tr("Create Project"), menuProject);
	actionLoadProject = new QAction(tr("Load Project"), menuProject);
	actionCloseProject = new QAction(tr("Close Project"), menuProject);
	actionExit = new QAction(tr("Exit"), menuProject);
	actionSettings = new QAction(tr("Settings"), menuSettings);
	actionPlugins = new QAction(tr("Plugins"), menuSettings);
	
	menuProject->addAction(actionCreateProject);
	menuProject->addAction(actionLoadProject);
	menuProject->addAction(actionCloseProject);
	menuProject->addSeparator();
	menuProject->addAction(actionExit);
	menuSettings->addAction(actionSettings);
	menuSettings->addAction(actionPlugins);
	
	menubar->addMenu(menuProject);
	menubar->addMenu(menuSettings);
}

void CDevStudio::initConnections()
{
	connect(actionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionCreateProjectTrigger()));
	connect(actionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionLoadProjectTrigger()));
	connect(actionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProjectTrigger()));
	connect(actionExit, SIGNAL(triggered(bool)), this, SLOT(actionExitTrigger()));
	connect(actionSettings, SIGNAL(triggered(bool)), this, SLOT(actionSettingsTrigger()));
	connect(actionPlugins, SIGNAL(triggered(bool)), this, SLOT(actionPluginsTrigger()));
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
	cdevstudioPlatform->initPlugins();
}

void CDevStudio::actionCreateProjectTrigger()
{
	if(cdevstudioPlatform->getProject() == nullptr)
	{
		DialogCreateProject *dialog = new DialogCreateProject(cdevstudioPlatform->getProjectTemplates(), this);
		if(dialog->exec() == QDialog::Accepted)
		{
			if(!dialog->getProjectDirectory().isEmpty() && !dialog->getProjectName().isEmpty() && !dialog->getProjectTemplate().isEmpty())
			{
				if(cdevstudioPlatform->createProject(dialog->getProjectDirectory(), dialog->getProjectName(), dialog->getProjectTemplate()) != nullptr)
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
	if(cdevstudioPlatform->getProject() == nullptr)
	{
		QString projectfile = QFileDialog::getOpenFileName(this, tr("Select a project"), QDir::homePath(), "CDevStudio (*.cdev)");
		if(!projectfile.isEmpty())
		{
			if(cdevstudioPlatform->loadProject(projectfile) != nullptr)
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
	if(cdevstudioPlatform->getProject() != nullptr)
	{
		cdevstudioPlatform->closeProject();
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
	DialogPlugins *dialog = new DialogPlugins(cdevstudioPlatform->getPlugins(), this);
	dialog->exec();
}
