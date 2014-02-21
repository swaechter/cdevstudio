#ifndef CDEVSTUDIOPROJECT_H
#define CDEVSTUDIOPROJECT_H

#include <QtCore/QString>

#include "CDevStudioPlatformExport.h"

class CDEVSTUDIOPLATFORM_API CDevStudioProject
{
public:
	CDevStudioProject(const QString &projectname, const QString &projectdirectory);
	QString getProjectName();
	QString getProjectDirectory();
	QString getProjectFile();
	
private:
	QString dataProjectName;
	QString dataProjectDirectory;
};

#endif // CDEVSTUDIOPROJECT_H