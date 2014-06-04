#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QtCore/QObject>

#include "PlatformExport.h"
#include "Window.h"

class CDEVSTUDIOPLATFORM_EXPORT WindowManager : public QObject
{
	Q_OBJECT
	
public:
	WindowManager(Window *window, QObject *parent);
	Window *getWindow();
	
private:
	Window *m_Window;
};

#endif // WINDOWMANAGER_H
