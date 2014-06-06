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

void Project::addFile(QString file)
{
	m_Files.append(file);
	m_Files.removeDuplicates();
}

void Project::removeFile(QString file)
{
	m_Files.removeOne(file);
}

QStringList Project::getFiles()
{
	return m_Files;
}
