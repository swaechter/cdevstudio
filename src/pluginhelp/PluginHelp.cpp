#include "PluginHelp.h"

PluginHelp::PluginHelp()
{
	m_PluginCore = (PluginCore *) IPlatform::getInstance()->getPluginManager()->getPlugin("Core");
	
	m_Help = new QAction(tr("Help"), m_PluginCore->getWindow()->getHelpMenu());
	m_About = new QAction(tr("About"), m_PluginCore->getWindow()->getHelpMenu());
	
	m_PluginCore->getWindow()->getHelpMenu()->addAction(m_Help);
	m_PluginCore->getWindow()->getHelpMenu()->addAction(m_About);
	
	connect(m_Help, SIGNAL(triggered(bool)), this, SLOT(actionHelp()));
	connect(m_About, SIGNAL(triggered(bool)), this, SLOT(actionAbout()));
	
	qDebug() << "PluginHelp";
}

PluginHelp::~PluginHelp()
{
}

QString PluginHelp::getName()
{
	return QString(tr("Help"));
}

QString PluginHelp::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginHelp::getDescription()
{
	return QString(tr("PluginHelp provides a help system"));
}

void PluginHelp::actionHelp()
{
	DialogHelp *dialog = new DialogHelp(m_PluginCore->getWindow());
	dialog->exec();
}

void PluginHelp::actionAbout()
{
	DialogAbout *dialog = new DialogAbout(m_PluginCore->getWindow());
	dialog->exec();
}
