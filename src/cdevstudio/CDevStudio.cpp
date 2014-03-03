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
	DialogCreateProject *dialog = new DialogCreateProject(this);
	if(dialog->exec() == QDialog::Accepted)
	{
		if(!dialog->getProjectDirectory().isEmpty() && !dialog->getProjectName().isEmpty() && !dialog->getProjectTemplate().isEmpty())
		{
		}
		else
		{
			QMessageBox::critical(this, tr("Error"), tr("Project cannot be created because some important information are missing"));
		}
	}
}

void CDevStudio::actionLoadProjectTrigger()
{
}

void CDevStudio::actionCloseProjectTrigger()
{
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
