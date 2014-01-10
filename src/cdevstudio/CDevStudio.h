#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QMessageBox>
#include <cdevstudioplatform/CDevStudioPlatform.h>
#include <cdevstudioplatform/CDevStudioProject.h>
#include <cdevstudiocodeedit/CDevStudioCodeEdit.h>

#include "ui_CDevStudio.h"
#include "ProjectExplorerView.h"
#include "ObjectExplorerView.h"
#include "DialogCreateProject.h"
#include "DialogFindText.h"
#include "DialogReplaceText.h"
#include "DialogProjectSettings.h"
#include "DialogSettings.h"
#include "DialogHelp.h"
#include "DialogAbout.h"

class CDevStudio : public QMainWindow, private Ui::CDevStudio
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	CDevStudioPlatform *cdevstudioPlatform;
	CDevStudioProject *cdevstudioProject;
	ProjectExplorerView *projectView;
	ObjectExplorerView *objectView;
	
private slots:
	void initPlatform();
	void initWindow();
	void initProjectDock();
	void initObjectDock();
	void initConnections();
	void initTranslation();
	void initWelcomeWidget();
	void actionCreateProjectTrigger();
	void actionLoadProjectTrigger();
	void actionCloseProjectTrigger();
	void actionExitTrigger();
	void actionCreateFileTrigger();
	void actionDeleteFileTrigger();
	void actionRenameFileTrigger();
	void actionFindTextTrigger();
	void actionReplaceTextTrigger();
	void actionBuildTrigger();
	void actionRunTrigger();
	void actionProjectSettingsTrigger();
	void actionSettingsTrigger();
	void actionProjectExplorerTrigger();
	void actionObjectExplorerTrigger();
	void actionConsoleTrigger();
	void actionHelpTrigger();
	void actionAboutTrigger();
};

#endif // CDEVSTUDIO_H
