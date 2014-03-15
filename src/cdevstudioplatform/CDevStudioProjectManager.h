#ifndef CDEVSTUDIOPROJECTMANAGER_H
#define CDEVSTUDIOPROJECTMANAGER_H

#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioProjectTemplate.h"
#include "CDevStudioProject.h"
#include "CDevStudioBackend.h"

class CDEVSTUDIOPLATFORM_API CDevStudioProjectManager
{
public:
	CDevStudioProjectManager();
	~CDevStudioProjectManager();
	void addProjectTemplate(CDevStudioProjectTemplate projecttemplate);
	QList<CDevStudioProjectTemplate> getProjectTemplates();
	CDevStudioProject *createProject(QString projectname, QString projectdirectory, QString projecttemplatestring);
	CDevStudioProject *loadProject(QString projectfile);
	CDevStudioProject *getProject();
	void closeProject();
	
private:
	QList<CDevStudioProjectTemplate> m_ProjectTemplates;
	CDevStudioProject *m_Project;
	CDevStudioBackend m_Backend;
	
	void closePossibleProject();
};

#endif // CDEVSTUDIOPROJECTMANAGER_H
