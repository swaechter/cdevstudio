#include "DialogCreateProject.h"

DialogCreateProject::DialogCreateProject(QList<ProjectTemplate> projecttemplates, QWidget *parent): QDialog(parent)
{
	setupUi(this);
	
	lineEditDirectory->setText(QDir::homePath());
	
	foreach(ProjectTemplate projecttemplate, projecttemplates)
	{
		comboBoxTemplate->addItem(projecttemplate.getName());
	}
}

QString DialogCreateProject::getProjectName()
{
	return lineEditName->text();
}

QString DialogCreateProject::getProjectDirectory()
{
	return lineEditDirectory->text();
}

QString DialogCreateProject::getProjectTemplate()
{
	return comboBoxTemplate->currentText();
}
