#include "Project.h"

Project::Project(const QString &name, const QString &directory)
{
	m_Name = name;
	m_Directory = directory;
}

QString Project::getName()
{
	return m_Name;
}

QString Project::getDirectory()
{
	return m_Directory;
}

QString Project::getProjectFile()
{
	return QString(m_Directory + QString("Project.cdev"));
}
