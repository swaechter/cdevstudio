#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QMessageBox>
#include <QtCore/QPluginLoader>
#include <QtCore/QDir>
#include <cdevstudioplatform/CDevStudioPlatform.h>
#include <cdevstudioplatform/CDevStudioWindow.h>
#include <cdevstudioplatform/CDevStudioMenuBar.h>
#include <cdevstudioplatform/CDevStudioMenu.h>
#include <cdevstudioplatform/CDevStudioAction.h>
#include <cdevstudioplatform/CDevStudioProject.h>
#include <cdevstudioplatform/ICDevStudioPlugin.h>

#include <QtCore/QDebug>

#include "DialogCreateProject.h"
#include "DialogSettings.h"

class CDevStudio : public CDevStudioWindow
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	CDevStudioPlatform *cdevstudioPlatform;
	CDevStudioMenu *menuProject;
	CDevStudioMenu *menuSettings;
	CDevStudioAction *actionCreateProject;
	CDevStudioAction *actionLoadProject;
	CDevStudioAction *actionCloseProject;
	CDevStudioAction *actionExit;
	CDevStudioAction *actionSettings;
	CDevStudioAction *actionPlugins;
	
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
