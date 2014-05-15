#include "PluginProjectExplorer.h"

PluginProjectExplorer::PluginProjectExplorer()
{
	m_PluginCore = (PluginCore *) IPlatform::getInstance()->getPluginManager()->getPlugin("Core");
	m_PluginProjects = (PluginProjects *) IPlatform::getInstance()->getPluginManager()->getPlugin("Projects");
	qDebug() << "PluginProjectExplorer";
}

PluginProjectExplorer::~PluginProjectExplorer()
{

}

QString PluginProjectExplorer::getName()
{
	return QString(tr("ProjectExplorer"));
}

QString PluginProjectExplorer::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjectExplorer::getDescription()
{
	return QString(tr("PluginProjectExplorer provides a basic project view"));
}
