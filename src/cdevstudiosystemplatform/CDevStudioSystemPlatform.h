#ifndef CDEVSTUDIOSYSTEMPLATFORM_H
#define CDEVSTUDIOSYSTEMPLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QStandardPaths>
#include <QtCore/QDebug>
#include <cdevstudiobackend/CDevStudioBackend.h>

#include "CDevStudioSystemPlatformExport.h"

class CDEVSTUDIOSYSTEMPLATFORM_API CDevStudioSystemPlatform : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioSystemPlatform();
	~CDevStudioSystemPlatform();
	QStringList getAvailableLocales();
	QString getLocalePath(const QString &locale);
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOSYSTEMPLATFORM_H
