#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QAction>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

#include "PlatformExport.h"
#include "MenuBar.h"
#include "TabWidget.h"
#include "Settings.h"

class CDEVSTUDIOPLATFORM_EXPORT Window : public QMainWindow
{
	Q_OBJECT
	
public:
	Window();
	MenuBar *getMenuBar();
	TabWidget *getTabWidget();
	Settings *getSettingsDialog();
	
private:
	MenuBar *m_Menubar;
	TabWidget *m_TabWidget;
	Settings *m_Settings;
};

#endif // WINDOW_H
