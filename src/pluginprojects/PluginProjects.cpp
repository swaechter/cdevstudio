#include "PluginProjects.h"

PluginProjects::PluginProjects()
{
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

void PluginProjects::addTemplate(QString name, QString description, QStringList files)
{
	m_Templates.append(ProjectTemplate(name, description, files));
}

QList< ProjectTemplate > PluginProjects::getTemplates()
{
	return m_Templates;
}
