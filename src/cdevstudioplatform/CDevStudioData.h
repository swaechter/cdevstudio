#ifndef CDEVSTUDIODATA_H
#define CDEVSTUDIODATA_H

#include <QtCore/QString>
#include <QtCore/QList>

#include "CDevStudioProjectTemplate.h"
#include "CDevStudioProject.h"
#include "ICDevStudioPlugin.h"

class CDevStudioData
{
public:
	void setPlugins(QList<ICDevStudioPlugin *> plugins);
	QList<ICDevStudioPlugin *> getPlugins();
	void addProjectTemplate(CDevStudioProjectTemplate projecttemplate);
	QList<CDevStudioProjectTemplate> getProjectTemplates();
	void setProject(CDevStudioProject *project);
	CDevStudioProject *getProject();
	void clearProject();
	
private:
	QList<ICDevStudioPlugin *> dataPlugins;
	QList<CDevStudioProjectTemplate> dataProjectTemplates;
	CDevStudioProject *dataProject = nullptr;
};
#endif // CDEVSTUDIODATA_H
