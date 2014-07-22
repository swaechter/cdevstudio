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
	if(!getProject())
	{
		directory = directory.append(QString("/")) + name + QString("/");
		
		m_Project->setName(name);
		m_Project->setLocation(directory);
		
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
	if(!getProject())
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

void ProjectManager::openFile(QString file)
{
	if(getProject() && !file.isEmpty() && !m_Project->getFiles().contains(file))
	{
		QFileInfo fileinfo(m_Project->getLocation() + file);
		if(!fileinfo.isDir())
		{
			m_Project->addFile(file);
			emit fileOpened(file);
		}
	}
}

void ProjectManager::closeFile(QString file)
{
	if(getProject() && !file.isEmpty() && m_Project->getFiles().contains(file))
	{
		m_Project->removeFile(file);
		emit fileClosed(file);
	}
}

void ProjectManager::closeProject()
{
	if(getProject())
	{
		foreach(QString file, m_Project->getFiles())
		{
			closeFile(file);
		}
		m_Project->setName(QString());
		m_Project->setLocation(QString());
		emit projectClosed();
	}
}
