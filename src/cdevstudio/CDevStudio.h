#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <cdevstudioplatform/Platform.h>
#include <cdevstudioplatform/WindowManager.h>
#include <cdevstudioplatform/Window.h>
#include <cdevstudioplatform/ProjectManager.h>
#include <cdevstudioplatform/Project.h>
#include <cdevstudioplatform/interfaces/IPlugin.h>

#include "DialogCreateProject.h"
#include "DialogSettings.h"
#include "DialogPlugins.h"
#include "DialogHelp.h"
#include "DialogAbout.h"

class CDevStudio : public Window
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	Platform *m_Platform;
	QMenu *m_MenuProject;
	QMenu *m_MenuSettings;
	QMenu *m_MenuHelp;
	QAction *m_ActionCreateProject;
	QAction *m_ActionLoadProject;
	QAction *m_ActionCloseProject;
	QAction *m_ActionExit;
	QAction *m_ActionSettings;
	QAction *m_ActionPlugins;
	QAction *m_ActionHelp;
	QAction *m_ActionAbout;
	
private slots:
	void initPlatform();
	void initWindow();
	void initMenubar();
	void initStatusbar();
	void initConnections();
	void initWelcomeWidget();
	void initPlugins();
	void actionCreateProjectTrigger();
	void actionLoadProjectTrigger();
	void actionCloseProjectTrigger();
	void actionExitTrigger();
	void actionSettingsTrigger();
	void actionPluginsTrigger();
	void actionHelpTrigger();
	void actionAboutTrigger();
};

#endif // CDEVSTUDIO_H
