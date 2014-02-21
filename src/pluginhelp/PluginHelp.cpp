#include "PluginHelp.h"

PluginHelp::PluginHelp()
{
	CDevStudioMenuBar *menubar = CDevStudioPlatform::getInstance()->getWindow()->getMenuBar();
	
	CDevStudioMenu *menuhelp = new CDevStudioMenu(tr("Help"), menubar);
	CDevStudioAction *actionhelp = new CDevStudioAction(tr("Help"), menuhelp);
	CDevStudioAction *actionabout = new CDevStudioAction(tr("About"), menuhelp);
	
	menuhelp->addAction(actionhelp);
	menuhelp->addAction(actionabout);
	
	menubar->addMenu(menuhelp);
	
	connect(actionhelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTriggered()));
	connect(actionabout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTriggered()));
}

PluginHelp::~PluginHelp()
{
}

QString PluginHelp::getPluginName()
{
	return QString(tr("Help"));
}

QString PluginHelp::getPluginVersion()
{
	return QString(tr("0.0.6"));
}

QString PluginHelp::getPluginDescription()
{
	return QString(tr("PluginHelp provides the help and about dialogues."));
}

QStringList PluginHelp::getPluginDependencies()
{
	return QStringList();
}

void PluginHelp::actionHelpTriggered()
{
	CDevStudioBackend *backend = CDevStudioPlatform::getInstance()->getBackend();
	DialogHelp *dialog = new DialogHelp(CDevStudioPlatform::getInstance()->getWindow());
	dialog->setHelpText(backend->readFile(":/data/help.html"));
	dialog->exec();
}

void PluginHelp::actionAboutTriggered()
{
	CDevStudioBackend *backend = CDevStudioPlatform::getInstance()->getBackend();
	DialogAbout *dialog = new DialogAbout(CDevStudioPlatform::getInstance()->getWindow());
	dialog->setAboutText(backend->readFile(":/data/about_about.html"));
	dialog->setLicenseText(backend->readFile(":/data/about_license.html"));
	dialog->setThankstoText(backend->readFile(":/data/about_thanksto.html"));
	dialog->exec();
}
