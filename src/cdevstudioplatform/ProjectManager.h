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
	bool closeProject();
	bool createFile(QString file);
	bool renameFile(QString oldfile, QString newfile);
	bool deleteFile(QString file);
	bool openFile(QString file);
	bool writeFile(QString file, QString text);
	bool closeFile(QString file);
	bool isFilepathInProject(QString filepath);
	
private:
	Project *m_Project;
	
signals:
	void projectOpened();
	void projectClosed();
	void fileOpened(QString file);
	void fileReopened(QString file);
	void fileClosed(QString file);
};

#endif // PROJECTMANAGER_H
