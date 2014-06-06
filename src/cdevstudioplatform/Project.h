#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QString>
#include <QtCore/QStringList>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT Project
{
public:
	Project(QString name, QString location);
	QString getName();
	QString getLocation();
	QString getProjectFile();
	void addFile(QString file);
	void removeFile(QString file);
	QStringList getFiles();
	
private:
	QString m_Name;
	QString m_Location;
	QStringList m_Files;
};

#endif // PROJECT_H
