#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "PlatformExport.h"
#include "ProjectTemplate.h"
#include "Project.h"
#include "Backend.h"

class CDEVSTUDIOPLATFORM_EXPORT ProjectManager : public QObject
{
	Q_OBJECT
	
public:
	ProjectManager();
	~ProjectManager();
	void addProjectTemplate(QString name, QString description, QStringList files);
	QList<ProjectTemplate> getProjectTemplates();
	Project *createProject(QString name, QString directory, QString templatestring);
	Project *loadProject(QString projectfile);
	Project *getProject();
	void closeProject();
	
private:
	QList<ProjectTemplate> m_ProjectTemplates;
	Project *m_Project;
	Backend m_Backend;
	
	void setProject(Project *project);
	void closePossibleProject();
	
signals:
	void projectOpen(Project *project);
	void projectClose(Project *project);
};

#endif // PROJECTMANAGER_H
