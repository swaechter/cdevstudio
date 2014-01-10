#ifndef DIALOGCREATEPROJECT_H
#define DIALOGCREATEPROJECT_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>

#include "ui_DialogCreateProject.h"

class DialogCreateProject : public QDialog, Ui::DialogCreateProject
{
	Q_OBJECT
	
public:
	DialogCreateProject(QWidget *parent);
	QString getProjectDirectory();
	QString getProjectName();
	
private slots:
	void actionNavigateClick();
};

#endif
