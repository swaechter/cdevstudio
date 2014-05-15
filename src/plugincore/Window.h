#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>

#include "PluginCoreExport.h"

class PLUGINCORE_EXPORT Window : public QMainWindow
{
	Q_OBJECT
	
public:
	Window();
	~Window();
};

#endif // WINDOW_H
