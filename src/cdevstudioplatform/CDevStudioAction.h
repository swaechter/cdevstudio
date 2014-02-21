#ifndef CDEVSTUDIOACTION_H
#define CDEVSTUDIOACTION_H

#include <QtWidgets/QAction>

#include "CDevStudioPlatformExport.h"

class CDEVSTUDIOPLATFORM_API CDevStudioAction : public QAction
{
	Q_OBJECT
	
public:
	CDevStudioAction(const QString &text, QWidget *parent);
	~CDevStudioAction();
};

#endif // CDEVSTUDIOACTION_H
