#ifndef CDEVSTUDIOPLATFORM_H
#define CDEVSTUDIOPLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioPlatformPlugin.h"
#include "CDevStudioWindow.h"
#include "CDevStudioBackend.h"
#include "CDevStudioData.h"
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
	CDevStudioBackend *getBackend();
	CDevStudioData *getData();
	
	CDevStudioProject *createProject(QString projectdirectory, QString projectname, QString projecttemplatestring);
	CDevStudioProject *loadProject(QString projectfile);
	void closeProject();
	
private:
	CDevStudioPlatformPlugin *cdevstudioPlatformPlugins;
	CDevStudioWindow *cdevstudioWindow;
	CDevStudioBackend cdevstudioBackend;
	CDevStudioData cdevstudioData;
	
private slots:
	void addProjectTemplate(CDevStudioProjectTemplate projecttemplate);
};

#endif // CDEVSTUDIOPLATFORM_H
