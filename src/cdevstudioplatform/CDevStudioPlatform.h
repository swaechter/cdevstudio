#ifndef CDEVSTUDIOPLATFORM_H
#define CDEVSTUDIOPLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QPluginLoader>
#include <QtCore/QList>
#include <QtCore/QDebug>

#include "CDevStudioPlatformExport.h"
#include "CDevStudioPlatformPlugin.h"
#include "CDevStudioWindow.h"
#include "CDevStudioProject.h"
#include "ICDevStudioPlugin.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatform : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioPlatform(CDevStudioWindow *window);
	~CDevStudioPlatform();
	void initPlugins();
	CDevStudioPlatformPlugin *getPluginPlatform();
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOPLATFORM_H
