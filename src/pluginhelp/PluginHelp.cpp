#include "PluginHelp.h"

PluginHelp::PluginHelp()
{
}

PluginHelp::~PluginHelp()
{
}

void PluginHelp::init(CDevStudioPlatformPlugin *platformplugin)
{
	dataPlatformPlugin = platformplugin;
	
	CDevStudioMenuBar *menubar = dataPlatformPlugin->getWindow()->getMenuBar();
	
	CDevStudioMenu *menuhelp = new CDevStudioMenu(tr("Help"), menubar);
	CDevStudioAction *actionhelp = new CDevStudioAction(tr("Help"), menuhelp);
	CDevStudioAction *actionabout = new CDevStudioAction(tr("About"), menuhelp);
	
	menuhelp->addAction(actionhelp);
	menuhelp->addAction(actionabout);
	
	menubar->addMenu(menuhelp);
	
	connect(actionhelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTriggered()));
	connect(actionabout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTriggered()));
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
	DialogHelp *dialog = new DialogHelp(dataPlatformPlugin->getWindow());
	dialog->exec();
}

void PluginHelp::actionAboutTriggered()
{
	DialogAbout *dialog = new DialogAbout(dataPlatformPlugin->getWindow());
	dialog->exec();
}
