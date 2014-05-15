#include "PluginProjectWizard.h"

PluginProjectWizard::PluginProjectWizard()
{
	m_PluginCore = (PluginCore *) IPlatform::getInstance()->getPluginManager()->getPlugin("Core");
	m_PluginProjects = (PluginProjects *) IPlatform::getInstance()->getPluginManager()->getPlugin("Projects");
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
