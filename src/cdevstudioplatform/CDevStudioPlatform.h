#ifndef CDEVSTUDIOPLATFORM_H
#define CDEVSTUDIOPLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioPlatformPlugin.h"
#include "CDevStudioWindow.h"
#include "CDevStudioProject.h"
#include "CDevStudioProjectTemplate.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatform : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioPlatform(CDevStudioWindow *window);
	~CDevStudioPlatform();
	void initPlugins();
	CDevStudioWindow *getWindow();
	QList<CDevStudioProjectTemplate> getProjectTemplates();
	QList<ICDevStudioPlugin *> getPlugins();
	
	CDevStudioProject *createProject(QString projectdirectory, QString projectname, QString projecttemplatestring);
	CDevStudioProject *loadProject(QString projectfile);
	CDevStudioProject *getProject();
	void closeProject();
	
private:
	CDevStudioWindow *cdevstudioWindow;
	CDevStudioPlatformPlugin *cdevstudioPlatformPlugins;;
	CDevStudioBackend *cdevstudioBackend;
	CDevStudioProject *cdevstudioProject;
	QList<CDevStudioProjectTemplate> cdevstudioProjectTemplates;
	QList<ICDevStudioPlugin *> cdevstudioPlugins;
	
private slots:
	void addProjectTemplate(CDevStudioProjectTemplate projecttemplate);
};

#endif // CDEVSTUDIOPLATFORM_H
