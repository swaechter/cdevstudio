#include "CDevStudioProject.h"

CDevStudioProject::CDevStudioProject(const QString &projectname, const QString &projectdirectory)
{
	dataProjectName = projectname;
	dataProjectDirectory = projectdirectory;
}

QString CDevStudioProject::getProjectName()
{
	return dataProjectName;
}

QString CDevStudioProject::getProjectDirectory()
{
	return dataProjectDirectory;
}

QString CDevStudioProject::getProjectFile()
{
	return QString(getProjectDirectory() + QString("Project.cdev"));
}
