#include "CDevStudioProject.h"

CDevStudioProject::CDevStudioProject(const QString &projectname, const QString &projectdirectory)
{
	m_ProjectName = projectname;
	m_ProjectDirectory = projectdirectory;
}

QString CDevStudioProject::getProjectName()
{
	return m_ProjectName;
}

QString CDevStudioProject::getProjectDirectory()
{
	return m_ProjectDirectory;
}

QString CDevStudioProject::getProjectFile()
{
	return QString(m_ProjectDirectory + QString("Project.cdev"));
}
