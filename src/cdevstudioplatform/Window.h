#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

#include "PlatformExport.h"
#include "Settings.h"

enum MenuTypes
{
	MenuProject,
	MenuFile,
	MenuEdit,
	MenuView,
	MenuSettings,
	MenuHelp
};

class CDEVSTUDIOPLATFORM_EXPORT Window : public QMainWindow
{
	Q_OBJECT
	
public:
	Window();
	virtual ~Window();
	QMenu *getMenu(MenuTypes type);
	QTabWidget *getTabWidget();
	Settings *getSettingsDialog();
	
private:
	QMenu *m_MenuProject;
	QMenu *m_MenuFile;
	QMenu *m_MenuEdit;
	QMenu *m_MenuView;
	QMenu *m_MenuSettings;
	QMenu *m_MenuHelp;
	QTabWidget *m_TabWidget;
	Settings *m_Settings;
	
	void initWindow();
	void initMenues();
	
private slots:
	void closeTab(int index);
	
signals:
	void closeTabRequested(QString name);
};

#endif // WINDOW_H
