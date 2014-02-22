#ifndef DIALOGCREATEPROJECT_H
#define DIALOGCREATEPROJECT_H

#include <QtWidgets/QDialog>

#include "ui_DialogCreateProject.h"

class DialogCreateProject : public QDialog, private Ui::DialogCreateProject
{
	Q_OBJECT
	
public:
	DialogCreateProject(QWidget *parent);
	QString getProjectDirectory();
	QString getProjectName();
	QString getProjectTemplate();
};

#endif
