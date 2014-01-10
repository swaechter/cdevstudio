#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTreeView>
#include <cdevstudioplatform/CDevStudioPlatform.h>
#include <cdevstudiocodeedit/CDevStudioCodeEdit.h>

#include "ui_CDevStudio.h"

class CDevStudio : public QMainWindow, private Ui::CDevStudio
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	CDevStudioPlatform *cdevstudioPlatform;
	
private slots:
	void initPlatform();
	void initWindow();
	void initProjectDock();
	void initObjectDock();
	void initConnections();
	void initTranslation();
	void initWelcomeWidget();
};

#endif // CDEVSTUDIO_H
