#include "PluginProjects.h"

PluginProjects::PluginProjects()
{
	m_PluginCore = (PluginCore *) IPlatform::getInstance()->getPluginManager()->getPlugin("Core");
	qDebug() << "PluginProjects";
}

PluginProjects::~PluginProjects()
{
}

QString PluginProjects::getName()
{
	return QString(tr("Projects"));
}

QString PluginProjects::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjects::getDescription()
{
	return QString(tr("PluginProjects provides some basic project templates"));
}
