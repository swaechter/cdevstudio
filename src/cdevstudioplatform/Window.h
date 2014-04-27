#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT Window : public QMainWindow
{
	Q_OBJECT
	
public:
	Window();
	~Window();
};

#endif // WINDOW_H
