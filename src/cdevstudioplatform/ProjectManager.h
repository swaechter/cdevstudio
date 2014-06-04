#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include "PlatformExport.h"

#include <QtCore/QObject>

class CDEVSTUDIOPLATFORM_EXPORT ProjectManager : public QObject
{
	Q_OBJECT
	
public:
	ProjectManager(QObject *parent);
	~ProjectManager();
};

#endif // PROJECTMANAGER_H
