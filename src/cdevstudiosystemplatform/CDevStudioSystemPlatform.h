#ifndef CDEVSTUDIOSYSTEMPLATFORM_H
#define CDEVSTUDIOSYSTEMPLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QList>
#include <cdevstudiobackend/CDevStudioBackend.h>

#include "CDevStudioSystemPlatformExport.h"

class CDEVSTUDIOSYSTEMPLATFORM_API CDevStudioSystemPlatform : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioSystemPlatform();
	~CDevStudioSystemPlatform();
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOSYSTEMPLATFORM_H
