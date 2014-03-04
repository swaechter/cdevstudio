#ifndef CDEVSTUDIOPLATFORMPLUGIN_H
#define CDEVSTUDIOPLATFORMPLUGIN_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioWindow.h"
#include "CDevStudioBackend.h"
#include "CDevStudioData.h"
#include "CDevStudioProjectTemplate.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatformPlugin : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioPlatformPlugin(CDevStudioWindow *window, CDevStudioBackend *backend, CDevStudioData *data);
	CDevStudioWindow *getWindow();
	CDevStudioBackend *getBackend();
	CDevStudioData *getData();
	void addProjectTemplate(CDevStudioProjectTemplate projecttemplate);
	
private:
	CDevStudioWindow *parentWindow;
	CDevStudioBackend *parentBackend;
	CDevStudioData *parentData;
	
signals:
	void addPlatformProjectTemplate(CDevStudioProjectTemplate projecttemplate);
};

#endif // CDEVSTUDIOPLATFORMPLUGIN_H
