#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <cdevstudioplatform/Platform.h>
#include <cdevstudioplatform/Window.h>

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
	void initPlatform();
	void initWindow();
	void loadPlugins();
	
	Platform *m_Platform;
	QAction *m_ActionExit;
	QAction *m_ActionSettings;
	QAction *m_ActionPlugins;
	QAction *m_ActionHelp;
	QAction *m_ActionAbout;
	
private slots:
	void actionExitTrigger();
	void actionSettingsTrigger();
	void actionPluginsTrigger();
	void actionHelpTrigger();
	void actionAboutTrigger();
};

#endif // CDEVSTUDIO_H
