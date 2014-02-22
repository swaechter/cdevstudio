#include "CDevStudio.h"

CDevStudio::CDevStudio() : CDevStudioWindow()
{
	initPlatform();
	initWindow();
	initMenubar();
	initStatusbar();
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
	cdevstudioPlatform = CDevStudioPlatform::getInstance();
}

void CDevStudio::initWindow()
{
	cdevstudioPlatform->setWindow(this);
	cdevstudioPlatform->getWindow()->setMinimumSize(800, 500);
	cdevstudioPlatform->getWindow()->setWindowTitle(tr("CDevStudio"));
}

void CDevStudio::initMenubar()
{
	CDevStudioMenuBar *menubar = cdevstudioPlatform->getWindow()->getMenuBar();
	
	menuProject = new CDevStudioMenu(tr("Project"), menubar);
	menuSettings = new CDevStudioMenu(tr("Settings"), menubar);
	actionCreateProject = new CDevStudioAction(tr("Create Project"), menuProject);
	actionLoadProject = new CDevStudioAction(tr("Load Project"), menuProject);
	actionCloseProject = new CDevStudioAction(tr("Close Project"), menuProject);
	actionExit = new CDevStudioAction(tr("Exit"), menuProject);
	actionSettings = new CDevStudioAction(tr("Settings"), menuSettings);
	actionPlugins = new CDevStudioAction(tr("Plugins"), menuSettings);
	
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

void CDevStudio::initStatusbar()
{
	CDevStudioStatusBar *statusbar = cdevstudioPlatform->getWindow()->getStatusBar();
	statusbar->clearMessage();
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
	QStringList paths;
	paths << "/home/simon/Workspace_C++/cdevstudio/build/src/pluginhelp/";
	foreach(QString path, paths)
	{
		QDir directory(path);
		QStringList filter;
		filter << "*plugin*.so" << "*plugin*.dll";
		QStringList files = directory.entryList(filter);
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file, this);
			QObject *object = loader.instance();
			if(object != nullptr)
			{
				ICDevStudioPlugin *plugin = qobject_cast<ICDevStudioPlugin *>(object);
				if(plugin != nullptr)
				{
					qDebug() << "CDevStudio: Loaded:" << plugin->getPluginName();
				}
				else
				{
					qDebug() << "CDevStudio: Cannot cast plugin" << file;
				}
			}
			else
			{
				qDebug() << "CDevStudio: Loader error:" << loader.errorString();
			}
		}
	}
}

void CDevStudio::actionCreateProjectTrigger()
{
	DialogCreateProject *dialog = new DialogCreateProject(this);
	if(dialog->exec() == QDialog::Accepted)
	{
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
	DialogPlugins *dialog = new DialogPlugins(this);
	dialog->exec();
}
