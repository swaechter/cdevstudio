#include "CDevStudio.h"

CDevStudio::CDevStudio() : QMainWindow()
{
	initPlatform();
	initWindow();
	initProjectDock();
	initObjectDock();
	initConnections();
	initTranslation();
	initWelcomeWidget();
}

CDevStudio::~CDevStudio()
{
	delete cdevstudioPlatform;
}

void CDevStudio::initPlatform()
{
	cdevstudioPlatform = new CDevStudioPlatform();
	cdevstudioProject = nullptr;
}

void CDevStudio::initWindow()
{
	setupUi(this);
}

void CDevStudio::initProjectDock()
{
	projectView = new ProjectExplorerView(this);
	dockWidgetProject->setWidget(projectView);
	
	filesystemModel = new QFileSystemModel(this);
}

void CDevStudio::initObjectDock()
{
	objectView = new ObjectExplorerView(this);
	dockWidgetObject->setWidget(objectView);
}

void CDevStudio::initConnections()
{
	connect(actionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionCreateProjectTrigger()));
	connect(actionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionLoadProjectTrigger()));
	connect(actionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProjectTrigger()));
	connect(actionExit, SIGNAL(triggered(bool)), this, SLOT(actionExitTrigger()));
	connect(actionCreateFile, SIGNAL(triggered(bool)), this, SLOT(actionCreateFileTrigger()));
	connect(actionDeleteFile, SIGNAL(triggered(bool)), this, SLOT(actionDeleteFileTrigger()));
	connect(actionRenameFile, SIGNAL(triggered(bool)), this, SLOT(actionRenameFileTrigger()));
	connect(actionFindText, SIGNAL(triggered(bool)), this, SLOT(actionFindTextTrigger()));
	connect(actionReplaceText, SIGNAL(triggered(bool)), this, SLOT(actionReplaceTextTrigger()));
	connect(actionBuild, SIGNAL(triggered(bool)), this, SLOT(actionBuildTrigger()));
	connect(actionRun, SIGNAL(triggered(bool)), this, SLOT(actionRunTrigger()));
	connect(actionProjectSettings, SIGNAL(triggered(bool)), this, SLOT(actionProjectSettingsTrigger()));
	connect(actionSettings, SIGNAL(triggered(bool)), this, SLOT(actionSettingsTrigger()));
	connect(actionProjectExplorer, SIGNAL(triggered(bool)), this, SLOT(actionProjectExplorerTrigger()));
	connect(actionObjectExplorer, SIGNAL(triggered(bool)), this, SLOT(actionObjectExplorerTrigger()));
	connect(actionConsole, SIGNAL(triggered(bool)), this, SLOT(actionConsoleTrigger()));
	connect(actionHelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTrigger()));
	connect(actionAbout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTrigger()));
}

void CDevStudio::initTranslation()
{
	retranslateUi(this);
}

void CDevStudio::initWelcomeWidget()
{
	CDevStudioCodeEdit *codeedit = new CDevStudioCodeEdit(this);
	QWidget *widget = dynamic_cast<QWidget *>(codeedit);
	if(widget != nullptr)
	{
		tabWidget->addTab(widget, tr("Welcome"));
	}
}

void CDevStudio::actionCreateProjectTrigger()
{
	if(cdevstudioProject == nullptr)
	{
		DialogCreateProject *dialog = new DialogCreateProject(this);
		if(dialog->exec() == QDialog::Accepted)
		{
			if(dialog->getProjectDirectory().length() && dialog->getProjectName().length())
			{
				CDevStudioProject *project = cdevstudioPlatform->createProject(dialog->getProjectName(), dialog->getProjectDirectory());
				if(project)
				{
					cdevstudioProject = project;
					filesystemModel->setRootPath(project->getProjectDirectory());
					projectView->setModel(filesystemModel);
					projectView->setRootIndex(filesystemModel->index(project->getProjectDirectory()));
					projectView->updateView();
				}
				else
				{
					QMessageBox::critical(this, tr("Error"), tr("The platform cannot create the new project"));
				}
			}
		}
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("Please close the current project before you create a new one"));
	}
}

void CDevStudio::actionLoadProjectTrigger()
{
	if(cdevstudioProject == nullptr)
	{
		QString projectfile = QFileDialog::getOpenFileName(this, tr("Select a project"), QDir::homePath(), "CDevStudio (*.cdev)");
		if(projectfile.length())
		{
			CDevStudioProject *project = cdevstudioPlatform->loadProject(projectfile);
			if(project)
			{
				cdevstudioProject = project;
				filesystemModel->setRootPath(project->getProjectDirectory());
				projectView->setModel(filesystemModel);
				projectView->setRootIndex(filesystemModel->index(project->getProjectDirectory()));
				projectView->updateView();
			}
		}
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("Please close the current project before you open a new one"));
	}
}

void CDevStudio::actionCloseProjectTrigger()
{
	if(cdevstudioProject != nullptr)
	{
		if(cdevstudioPlatform->closeProject(cdevstudioProject))
		{
			cdevstudioProject = nullptr;
			projectView->setModel(nullptr);
		}
		else
		{
			QMessageBox::critical(this, tr("Error"), tr("The platform cannot close the current project"));
		}
	}
}

void CDevStudio::actionExitTrigger()
{
	exit(EXIT_SUCCESS);
}

void CDevStudio::actionCreateFileTrigger()
{
	if(cdevstudioProject != nullptr)
	{
	}
}

void CDevStudio::actionDeleteFileTrigger()
{
	if(cdevstudioProject != nullptr)
	{
	}
}

void CDevStudio::actionRenameFileTrigger()
{
	if(cdevstudioProject != nullptr)
	{
	}
}

void CDevStudio::actionFindTextTrigger()
{
	if(cdevstudioProject != nullptr)
	{
	}
}

void CDevStudio::actionReplaceTextTrigger()
{
	if(cdevstudioProject != nullptr)
	{
	}
}

void CDevStudio::actionBuildTrigger()
{
	if(cdevstudioProject != nullptr)
	{
		if(cdevstudioPlatform->buildProject(cdevstudioProject))
		{
			textEditConsole->append(tr("Project build was succesful"));
		}
		else
		{
			textEditConsole->append(tr("Project build was not successful"));
		}
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("Please open an existing project or create a new one"));
	}
}

void CDevStudio::actionRunTrigger()
{
	if(cdevstudioProject != nullptr)
	{
		if(cdevstudioPlatform->runProject(cdevstudioProject))
		{
			textEditConsole->append(tr("Project started and exited without error codes"));
		}
		else
		{
			textEditConsole->append(tr("Project executable was not found or crashed during execution"));
		}
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("Please open an existing project or create a new one"));
	}
}

void CDevStudio::actionProjectSettingsTrigger()
{
	if(cdevstudioProject != nullptr)
	{
		DialogProjectSettings *dialog = new DialogProjectSettings(this);
		if(dialog->exec() == QDialog::Accepted)
		{
		}
	}
	else
	{
		QMessageBox::information(this, tr("Information"), tr("Please open an existing project or create a new one"));
	}
}

void CDevStudio::actionSettingsTrigger()
{
	DialogSettings *dialog = new DialogSettings(this);
	if(dialog->exec() == QDialog::Accepted)
	{
	}
}

void CDevStudio::actionProjectExplorerTrigger()
{
	if(actionProjectExplorer->isChecked())
	{
		dockWidgetProject->show();
	}
	else
	{
		dockWidgetProject->hide();
	}
}

void CDevStudio::actionObjectExplorerTrigger()
{
	if(actionObjectExplorer->isChecked())
	{
		dockWidgetObject->show();
	}
	else
	{
		dockWidgetObject->hide();
	}
}

void CDevStudio::actionConsoleTrigger()
{
	if(actionConsole->isChecked())
	{
		dockWidgetConsole->show();
	}
	else
	{
		dockWidgetConsole->hide();
	}
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
