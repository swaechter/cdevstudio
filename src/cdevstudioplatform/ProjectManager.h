#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QtCore/QObject>

#include "PlatformExport.h"
#include "Project.h"
#include "Backend.h"

class CDEVSTUDIOPLATFORM_EXPORT ProjectManager : public QObject
{
	Q_OBJECT
	
public:
	ProjectManager(QObject *parent);
	~ProjectManager();
	Project *createProject(QString name, QString directory, QStringList files);
	Project *loadProject(QString projectfile);
	Project *getProject();
	void openFile(QString file);
	void closeFile(QString file);
	void closeProject();
	
private:
	Project *m_Project;
	
signals:
	void projectOpened();
	void projectClosed();
	void fileOpened(QString file);
	void fileClosed(QString file);
};

#endif // PROJECTMANAGER_H
