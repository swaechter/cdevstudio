#ifndef CDEVSTUDIOPROJECTPLATFORM_H
#define CDEVSTUDIOPROJECTPLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QList>
#include <cdevstudiobackend/CDevStudioBackend.h>

#include "CDevStudioProjectPlatformExport.h"
#include "CDevStudioProject.h"

class CDEVSTUDIOPROJECTPLATFORM_API CDevStudioProjectPlatform : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioProjectPlatform();
	~CDevStudioProjectPlatform();
	CDevStudioProject *createProject(const QString &projectname, const QString &projectdirectory);
	CDevStudioProject *loadProject(const QString &projectfile);
	bool closeProject(CDevStudioProject *project);
	bool buildProject(CDevStudioProject *project);
	bool runProject(CDevStudioProject *project);
	QList<CDevStudioProject *> getProjects();
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOPROJECTPLATFORM_H
