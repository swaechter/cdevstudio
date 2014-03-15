#include "PluginHelp.h"

PluginHelp::PluginHelp()
{
}

PluginHelp::~PluginHelp()
{
}

void PluginHelp::init(CDevStudioPlatformPlugin *platformplugin)
{
	m_PlatformPlugin = platformplugin;
	
	QMenuBar *menubar = m_PlatformPlugin->getWindowManager()->getWindow()->menuBar();
	
	QMenu *menuhelp = new QMenu(tr("Help"), menubar);
	QAction *actionhelp = new QAction(tr("Help"), menuhelp);
	QAction *actionabout = new QAction(tr("About"), menuhelp);
	
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
	return QString(tr("0.0.7"));
}

QString PluginHelp::getPluginDescription()
{
	return QString(tr("PluginHelp provides the help and about dialogues"));
}

QStringList PluginHelp::getPluginDependencies()
{
	return QStringList();
}

void PluginHelp::actionHelpTriggered()
{
	DialogHelp *dialog = new DialogHelp(m_PlatformPlugin->getWindowManager()->getWindow());
	dialog->exec();
}

void PluginHelp::actionAboutTriggered()
{
	DialogAbout *dialog = new DialogAbout(m_PlatformPlugin->getWindowManager()->getWindow());
	dialog->exec();
}
