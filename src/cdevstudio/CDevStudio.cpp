#include "CDevStudio.h"

CDevStudio::CDevStudio() : QMainWindow()
{
	initPlatform();
	initWindow();
	initProjectDock();
	initObjectDock();
	initConnections();
	initTranslation();
	initWelcomeWidget();
}

CDevStudio::~CDevStudio()
{
	delete cdevstudioPlatform;
}

void CDevStudio::initPlatform()
{
	cdevstudioPlatform = new CDevStudioPlatform();
}

void CDevStudio::initWindow()
{
	setupUi(this);
}

void CDevStudio::initProjectDock()
{
	QTreeView *projectview = new QTreeView(dockWidgetProject);
	dockWidgetProject->setWidget(projectview);
}

void CDevStudio::initObjectDock()
{
	QTreeView *objectview = new QTreeView(dockWidgetObject);
	dockWidgetObject->setWidget(objectview);
}

void CDevStudio::initConnections()
{
}

void CDevStudio::initTranslation()
{
	retranslateUi(this);
}

void CDevStudio::initWelcomeWidget()
{
	CDevStudioCodeEdit *codeedit = new CDevStudioCodeEdit(this);
	QWidget *widget = dynamic_cast<QWidget *>(codeedit);
	if(widget != NULL)
	{
		tabWidget->addTab(widget, tr("Welcome"));
	}
}
