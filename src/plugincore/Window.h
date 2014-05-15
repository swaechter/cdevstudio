#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>

#include "PluginCoreExport.h"

class PLUGINCORE_EXPORT Window : public QMainWindow
{
	Q_OBJECT
	
public:
	Window();
	~Window();
	QMenu *getProjectMenu();
	QMenu *getSettingsMenu();
	QMenu *getHelpMenu();
	
private:
	QMenu *m_MenuProject;
	QMenu *m_MenuSettings;
	QMenu *m_MenuHelp;
};

#endif // WINDOW_H
