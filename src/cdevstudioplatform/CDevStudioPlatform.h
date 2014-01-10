#ifndef CDEVSTUDIOPLATFORM_H
#define CDEVSTUDIOPLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QList>
#include <cdevstudiobackend/CDevStudioBackend.h>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioProject.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatform : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioPlatform();
	~CDevStudioPlatform();
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

#endif // CDEVSTUDIOPLATFORM_H
