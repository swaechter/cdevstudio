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
	QString m_ProjectName;
	QString m_ProjectDirectory;
};

#endif // CDEVSTUDIOPROJECT_H
