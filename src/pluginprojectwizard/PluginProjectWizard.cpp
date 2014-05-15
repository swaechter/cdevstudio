#include "PluginProjectWizard.h"

PluginProjectWizard::PluginProjectWizard()
{
	m_PluginCore = (PluginCore *) IPlatform::getInstance()->getPluginManager()->getPlugin("Core");
	m_PluginProjects = (PluginProjects *) IPlatform::getInstance()->getPluginManager()->getPlugin("Projects");
	
	m_CreateProject = new QAction(tr("Create Project"), m_PluginCore->getWindow()->getProjectMenu());
	m_LoadProject = new QAction(tr("Load Project"), m_PluginCore->getWindow()->getProjectMenu());
	m_CloseProject = new QAction(tr("Close Project"), m_PluginCore->getWindow()->getProjectMenu());
	
	m_PluginCore->getWindow()->getProjectMenu()->addAction(m_CreateProject);
	m_PluginCore->getWindow()->getProjectMenu()->addAction(m_LoadProject);
	m_PluginCore->getWindow()->getProjectMenu()->addAction(m_CloseProject);
	
	connect(m_CreateProject, SIGNAL(triggered(bool)), this, SLOT(actionCreateProject()));
	connect(m_LoadProject, SIGNAL(triggered(bool)), this, SLOT(actionLoadProject()));
	connect(m_CloseProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProject()));
	
	qDebug() << "PluginProjectWizard";
}

PluginProjectWizard::~PluginProjectWizard()
{
}

QString PluginProjectWizard::getName()
{
	return QString(tr("ProjectWizard"));
}

QString PluginProjectWizard::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjectWizard::getDescription()
{
	return QString(tr("PluginProjectWizard provides the project wizards"));
}

void PluginProjectWizard::actionCreateProject()
{
	qDebug() << "TODO Create Project";
}

void PluginProjectWizard::actionLoadProject()
{
	qDebug() << "TODO Load Project";
}

void PluginProjectWizard::actionCloseProject()
{
	qDebug() << "TODO Close Project";
}
