#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT Project : public QObject
{
	Q_OBJECT
	
	friend class ProjectManager;
	
public:
	QString getName();
	QString getLocation();
	QString getProjectFile();
	
private:
	void setName(QString name);
	void setLocation(QString location);
	
	QString m_Name;
	QString m_Location;
};

#endif // PROJECT_H
