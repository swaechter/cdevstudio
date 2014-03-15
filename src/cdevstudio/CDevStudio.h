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
#include <cdevstudioplatform/CDevStudioPlatform.h>
#include <cdevstudioplatform/CDevStudioWindowManager.h>
#include <cdevstudioplatform/CDevStudioWindow.h>
#include <cdevstudioplatform/CDevStudioProjectManager.h>
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
	CDevStudioPlatform *m_Platform;
	QMenu *m_MenuProject;
	QMenu *m_MenuSettings;
	QAction *m_ActionCreateProject;
	QAction *m_ActionLoadProject;
	QAction *m_ActionCloseProject;
	QAction *m_ActionExit;
	QAction *m_ActionSettings;
	QAction *m_ActionPlugins;
	
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
