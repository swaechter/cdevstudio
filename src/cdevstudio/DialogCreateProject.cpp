#include "DialogCreateProject.h"

DialogCreateProject::DialogCreateProject(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
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
