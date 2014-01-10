#ifndef CDEVSTUDIOBACKEND_H
#define CDEVSTUDIOBACKEND_H

#include <QtCore/QObject>

#include "CDevStudioBackendExport.h"

class CDEVSTUDIOBACKEND_API CDevStudioBackend : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioBackend();
	~CDevStudioBackend();
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOBACKEND_H
