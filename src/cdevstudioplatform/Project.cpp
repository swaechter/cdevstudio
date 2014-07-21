#include "Project.h"

QString Project::getName()
{
	return m_Name;
}

QString Project::getLocation()
{
	return m_Location;
}

QString Project::getProjectFile()
{
	return m_Location + QString("Project.cdev");
}

void Project::setName(QString name)
{
	m_Name = name;
}

void Project::setLocation(QString location)
{
	m_Location = location;
}
