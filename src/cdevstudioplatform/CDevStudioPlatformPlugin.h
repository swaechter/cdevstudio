#ifndef CDEVSTUDIOPLATFORMPLUGIN_H
#define CDEVSTUDIOPLATFORMPLUGIN_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QList>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioWindow.h"
#include "CDevStudioProjectTemplate.h"
#include "CDevStudioBackend.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatformPlugin : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioPlatformPlugin(CDevStudioWindow *window, QList<ICDevStudioPlugin *> plugins, CDevStudioBackend *backend);
	CDevStudioWindow *getWindow();
	QList<ICDevStudioPlugin *> getPlugins();
	CDevStudioBackend *getBackend();
	void addProjectTemplate(CDevStudioProjectTemplate projecttemplate);
	
private:
	CDevStudioWindow *parentWindow;
	QList<ICDevStudioPlugin *> parentPlugins;
	CDevStudioBackend *parentBackend;
	
signals:
	void addPlatformProjectTemplate(CDevStudioProjectTemplate projecttemplate);
};

#endif // CDEVSTUDIOPLATFORMPLUGIN_H
