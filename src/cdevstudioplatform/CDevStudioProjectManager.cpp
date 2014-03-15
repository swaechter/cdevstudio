#include "CDevStudioProjectManager.h"

CDevStudioProjectManager::CDevStudioProjectManager()
{
	m_Project = nullptr;
}

CDevStudioProjectManager::~CDevStudioProjectManager()
{
	closePossibleProject();
}

void CDevStudioProjectManager::addProjectTemplate(CDevStudioProjectTemplate projecttemplate)
{
	m_ProjectTemplates.append(projecttemplate);
}

QList<CDevStudioProjectTemplate> CDevStudioProjectManager::getProjectTemplates()
{
	return m_ProjectTemplates;
}

CDevStudioProject *CDevStudioProjectManager::createProject(QString projectname, QString projectdirectory, QString projecttemplatestring)
{
	if(m_Project == nullptr)
	{
		projectdirectory = projectdirectory.append(QString("/") + projectname + QString("/"));
		m_Backend.createDirectory(projectdirectory);
		m_Backend.createFile(projectdirectory + QString("Project.cdev"));
		m_Backend.writeFile(projectdirectory + QString("Project.cdev"), projectname);
		
		closePossibleProject();
		m_Project = new CDevStudioProject(projectname, projectdirectory);
		
		foreach(CDevStudioProjectTemplate projecttemplate, m_ProjectTemplates)
		{
			if(projecttemplatestring.compare(projecttemplate.getTemplateName()) == 0)
			{
				foreach(QString file, projecttemplate.getTemplateFiles())
				{
					QString filepath = projectdirectory + m_Backend.getNameOfFile(file);
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

CDevStudioProject *CDevStudioProjectManager::loadProject(QString projectfile)
{
	if(!projectfile.isEmpty())
	{
		QString projectdirectory = m_Backend.getDirectoryOfFile(projectfile) + QString("/");
		QString projectname = m_Backend.readFile(projectfile);
		m_Project = new CDevStudioProject(projectname, projectdirectory);
		return m_Project;
	}
	else
	{
		return nullptr;
	}
}

CDevStudioProject *CDevStudioProjectManager::getProject()
{
	return m_Project;
}

void CDevStudioProjectManager::closeProject()
{
	closePossibleProject();
}

void CDevStudioProjectManager::closePossibleProject()
{
	if(m_Project != nullptr)
	{
		delete m_Project;
		m_Project = nullptr;
	}
}
