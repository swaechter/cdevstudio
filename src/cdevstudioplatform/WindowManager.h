#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "PlatformExport.h"
#include "Window.h"

class CDEVSTUDIOPLATFORM_EXPORT WindowManager
{
public:
	WindowManager(Window *window);
	WindowManager();
	Window *getWindow();
	
private:
	Window *m_Window;
};

#endif // WINDOWMANAGER_H
