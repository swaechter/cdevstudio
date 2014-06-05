#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

#include "PlatformExport.h"

enum MenuTypes
{
	Project,
	View,
	Settings,
	Help
};

class CDEVSTUDIOPLATFORM_EXPORT Window : public QMainWindow
{
	Q_OBJECT
	
public:
	Window();
	virtual ~Window();
	QMenu *getMenu(MenuTypes type);
	
private:
	QMenu *m_MenuProject;
	QMenu *m_MenuView;
	QMenu *m_MenuSettings;
	QMenu *m_MenuHelp;
	
	void initWindow();
	void initMenues();
};

#endif // WINDOW_H
