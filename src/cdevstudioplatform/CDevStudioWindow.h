#ifndef CDEVSTUDIOWINDOW_H
#define CDEVSTUDIOWINDOW_H

#include <QtWidgets/QMainWindow>

#include "CDevStudioMenuBar.h"
#include "CDevStudioStatusBar.h"

class CDevStudioWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	CDevStudioWindow();
	~CDevStudioWindow();
	CDevStudioMenuBar *getMenuBar();
	CDevStudioStatusBar *getStatusBar();
	
private:
	CDevStudioMenuBar *widgetMenuBar;
	CDevStudioStatusBar *widgetStatusBar;
};

#endif // CDEVSTUDIOWINDOW_H
