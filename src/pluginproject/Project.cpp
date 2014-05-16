#include "Project.h"

Project::Project(QString name, QString location)
{
	m_Name = name;
	m_Location = location;
}

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
