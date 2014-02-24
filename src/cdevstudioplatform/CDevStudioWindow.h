#ifndef CDEVSTUDIOWINDOW_H
#define CDEVSTUDIOWINDOW_H

#include <QtWidgets/QMainWindow>

#include "CDevStudioPlatformExport.h"

class CDEVSTUDIOPLATFORM_API CDevStudioWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	CDevStudioWindow();
	~CDevStudioWindow();
};

#endif // CDEVSTUDIOWINDOW_H
