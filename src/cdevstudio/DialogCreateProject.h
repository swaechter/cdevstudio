#ifndef DIALOGCREATEPROJECT_H
#define DIALOGCREATEPROJECT_H

#include <QtWidgets/QDialog>
#include <QtCore/QList>
#include <QtCore/QDir>
#include <cdevstudioplatform/CDevStudioProjectTemplate.h>

#include "ui_DialogCreateProject.h"

class DialogCreateProject : public QDialog, private Ui::DialogCreateProject
{
	Q_OBJECT
	
public:
	DialogCreateProject(QList<CDevStudioProjectTemplate> projecttemplates, QWidget *parent);
	QString getProjectName();
	QString getProjectDirectory();
	QString getProjectTemplate();
};

#endif
