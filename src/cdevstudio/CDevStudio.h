#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QMessageBox>
#include <cdevstudioplatform/CDevStudioPlatform.h>
#include <cdevstudioplatform/CDevStudioWindow.h>
#include <cdevstudioplatform/CDevStudioProject.h>
#include <cdevstudioplatform/ICDevStudioPlugin.h>

#include "DialogCreateProject.h"
#include "DialogSettings.h"
#include "DialogPlugins.h"

class CDevStudio : public CDevStudioWindow
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	CDevStudioPlatform *cdevstudioPlatform;
	QMenu *menuProject;
	QMenu *menuSettings;
	QAction *actionCreateProject;
	QAction *actionLoadProject;
	QAction *actionCloseProject;
	QAction *actionExit;
	QAction *actionSettings;
	QAction *actionPlugins;
	
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
};

#endif // CDEVSTUDIO_H
