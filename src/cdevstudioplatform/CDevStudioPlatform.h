#ifndef CDEVSTUDIOPLATFORM_H
#define CDEVSTUDIOPLATFORM_H

#include <QtCore/QObject>
#include <cdevstudiobackend/CDevStudioBackend.h>

#include "CDevStudioPlatformExport.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatform : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioPlatform();
	~CDevStudioPlatform();
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOPLATFORM_H
