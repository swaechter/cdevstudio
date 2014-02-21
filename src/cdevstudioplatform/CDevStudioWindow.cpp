#include "CDevStudioWindow.h"

CDevStudioWindow::CDevStudioWindow() : QMainWindow()
{
	widgetMenuBar = new CDevStudioMenuBar(this);
	setMenuBar(widgetMenuBar);
	
	widgetStatusBar = new CDevStudioStatusBar(this);
	setStatusBar(widgetStatusBar);
}

CDevStudioWindow::~CDevStudioWindow()
{
}

CDevStudioMenuBar *CDevStudioWindow::getMenuBar()
{
	return widgetMenuBar;
}

CDevStudioStatusBar *CDevStudioWindow::getStatusBar()
{
	return widgetStatusBar;
}
