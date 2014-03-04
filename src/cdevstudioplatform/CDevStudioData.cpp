#include "CDevStudioData.h"

void CDevStudioData::setPlugins(QList<ICDevStudioPlugin *> plugins)
{
	dataPlugins = plugins;
}

QList<ICDevStudioPlugin *> CDevStudioData::getPlugins()
{
	return dataPlugins;
}

void CDevStudioData::addProjectTemplate(CDevStudioProjectTemplate projecttemplate)
{
	dataProjectTemplates.append(projecttemplate);
}

QList<CDevStudioProjectTemplate> CDevStudioData::getProjectTemplates()
{
	return dataProjectTemplates;
}

void CDevStudioData::setProject(CDevStudioProject *project)
{
	dataProject = project;
}

CDevStudioProject *CDevStudioData::getProject()
{
	return dataProject;
}

void CDevStudioData::clearProject()
{
	if(dataProject != nullptr)
	{
		delete dataProject;
		dataProject = nullptr;
	}
}
