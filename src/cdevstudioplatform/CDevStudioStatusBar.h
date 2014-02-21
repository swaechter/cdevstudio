#ifndef CDEVSTUDIOSTATUSBAR_H
#define CDEVSTUDIOSTATUSBAR_H

#include <QtWidgets/QStatusBar>

#include "CDevStudioPlatformExport.h"

class CDEVSTUDIOPLATFORM_API CDevStudioStatusBar : public QStatusBar
{
	Q_OBJECT
	
public:
	CDevStudioStatusBar(QWidget *parent);
	~CDevStudioStatusBar();
};

#endif // CDEVSTUDIOSTATUSBAR_H
