#include "DialogCreateProject.h"

DialogCreateProject::DialogCreateProject(QList<CDevStudioProjectTemplate> projecttemplates, QWidget *parent): QDialog(parent)
{
	setupUi(this);
	
	lineEditDirectory->setText(QDir::homePath());
	
	foreach(CDevStudioProjectTemplate projecttemplate, projecttemplates)
	{
		comboBoxTemplate->addItem(projecttemplate.getTemplateName());
	}
}

QString DialogCreateProject::getProjectDirectory()
{
	return lineEditDirectory->text();
}

QString DialogCreateProject::getProjectName()
{
	return lineEditName->text();
}

QString DialogCreateProject::getProjectTemplate()
{
	return comboBoxTemplate->currentText();
}
