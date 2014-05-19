#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QString>

#include "PluginProjectsExport.h"

class PLUGINPROJECTS_EXPORT Project
{
public:
	Project(QString name, QString location);
	QString getName();
	QString getLocation();
	QString getProjectFile();
	
private:
	QString m_Name;
	QString m_Location;
};

#endif // PROJECT_H