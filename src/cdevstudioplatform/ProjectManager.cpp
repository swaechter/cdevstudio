#include "ProjectManager.h"

ProjectManager::ProjectManager() : QObject()
{
	m_Project = nullptr;
}

ProjectManager::~ProjectManager()
{
	closePossibleProject();
}


void ProjectManager::addProjectTemplate(QString name, QString description, QStringList files)
{
	m_ProjectTemplates.append(ProjectTemplate(name, description, files));
}

QList<ProjectTemplate> ProjectManager::getProjectTemplates()
{
	return m_ProjectTemplates;
}

Project *ProjectManager::createProject(QString name, QString directory, QString templatestring)
{
	if(m_Project == nullptr)
	{
		directory = directory.append(QString("/") + name + QString("/"));
		m_Backend.createDirectory(directory);
		m_Backend.createFile(directory + QString("Project.cdev"));
		m_Backend.writeFile(directory + QString("Project.cdev"), name);
		
		setProject(new Project(name, directory));
		
		foreach(ProjectTemplate projecttemplate, m_ProjectTemplates)
		{
			if(templatestring.compare(projecttemplate.getName()) == 0)
			{
				foreach(QString file, projecttemplate.getFiles())
				{
					QString filepath = directory + m_Backend.getNameOfFile(file);
					m_Backend.createFile(filepath);
					m_Backend.writeFile(filepath, m_Backend.readFile(file));
				}
				break;
			}
		}
		return m_Project;
	}
	else
	{
		return nullptr;
	}
}

Project *ProjectManager::loadProject(QString projectfile)
{
	if(!projectfile.isEmpty())
	{
		QString projectdirectory = m_Backend.getDirectoryOfFile(projectfile) + QString("/");
		QString projectname = m_Backend.readFile(projectfile);
		setProject(new Project(projectname, projectdirectory));
		return m_Project;
	}
	else
	{
		return nullptr;
	}
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
	emit projectOpen(m_Project);
}

void ProjectManager::closePossibleProject()
{
	if(m_Project != nullptr)
	{
		emit projectClose(m_Project);
		delete m_Project;
		m_Project = nullptr;
	}
}
