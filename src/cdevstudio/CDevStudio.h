#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <QtCore/QObject>

#include <cdevstudioplatform/Platform.h>
#include <cdevstudioplatform/IPluginManager.h>

#include <QDebug>

class CDevStudio : public QObject
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	void initPlatform();
	
	Platform *m_Platform;
	IPluginManager *manager;
};

#endif // CDEVSTUDIO_H
