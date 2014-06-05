#include "ProjectManager.h"

ProjectManager::ProjectManager(QObject *parent): QObject(parent)
{
	m_Project = nullptr;
}

ProjectManager::~ProjectManager()
{
	closePossibleProject();
}

Project *ProjectManager::createProject(QString name, QString directory, QStringList files)
{
	if(!m_Project)
	{
		directory = directory.append(QString("/") + name + QString("/"));
		Backend::createDirectory(directory);
		Backend::createFile(directory + QString("Project.cdev"));
		Backend::writeFile(directory + QString("Project.cdev"), name);
		
		setProject(new Project(name, directory));
		
		foreach(QString file, files)
		{
			QString filepath = directory + Backend::getNameOfFile(file);
			Backend::createFile(filepath);
			Backend::writeFile(filepath, Backend::readFile(file));
		}
	}
	return m_Project;
}

Project *ProjectManager::loadProject(QString projectfile)
{
	if(!projectfile.isEmpty())
	{
		QString projectdirectory = Backend::getDirectoryOfFile(projectfile) + QString("/");
		QString projectname = Backend::readFile(projectfile);
		setProject(new Project(projectname, projectdirectory));
	}
	return m_Project;
}

Project *ProjectManager::getProject()
{
	return m_Project;
}

void ProjectManager::closeProject()
{
	closePossibleProject();
}

void ProjectManager::setProject(Project *project)
{
	closePossibleProject();
	m_Project = project;
	emit projectOpen();
}

void ProjectManager::closePossibleProject()
{
	if(m_Project)
	{
		emit projectClose();
		delete m_Project;
		m_Project = nullptr;
	}
}