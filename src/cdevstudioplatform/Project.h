#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QString>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT Project
{
public:
	Project(const QString &name, const QString &directory);
	QString getName();
	QString getDirectory();
	QString getProjectFile();
	
private:
	QString m_Name;
	QString m_Directory;
};

#endif // PROJECT_H
