#include "ProjectManager.h"

ProjectManager::ProjectManager(QObject *parent): QObject(parent)
{
	m_Project = new Project();
}

ProjectManager::~ProjectManager()
{
	delete m_Project;
}

Project *ProjectManager::createProject(QString name, QString directory, QStringList files)
{
	if(m_Project->getName().isEmpty() && m_Project->getLocation().isEmpty())
	{
		m_Project->setName(name);
		m_Project->setLocation(directory);
		
		directory = directory.append(QString("/") + name + QString("/"));
		Backend::createDirectory(directory);
		Backend::createFile(directory + QString("Project.cdev"));
		Backend::writeFile(directory + QString("Project.cdev"), name);
		foreach(QString file, files)
		{
			QString filepath = directory + Backend::getNameOfFile(file);
			Backend::createFile(filepath);
			Backend::writeFile(filepath, Backend::readFile(file));
		}
		
		emit projectOpened();
		
		return m_Project;
	}
	else
	{
		return nullptr;
	}
}

Project *ProjectManager::loadProject(QString projectfile)
{
	if(m_Project->getName().isEmpty() && m_Project->getLocation().isEmpty())
	{
		QString projectdirectory = Backend::getDirectoryOfFile(projectfile) + QString("/");
		QString projectname = Backend::readFile(projectfile);
		m_Project->setName(projectname);
		m_Project->setLocation(projectdirectory);
		
		emit projectOpened();
		
		return m_Project;
	}
	else
	{
		return nullptr;
	}
}

Project *ProjectManager::getProject()
{
	if(!m_Project->getName().isEmpty() && !m_Project->getLocation().isEmpty())
	{
		return m_Project;
	}
	else
	{
		return nullptr;
	}
}

void ProjectManager::closeProject()
{
	m_Project->setName(QString());
	m_Project->setLocation(QString());
	emit projectClosed();
}
