#include "DialogCreateProject.h"

DialogCreateProject::DialogCreateProject(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	connect(pushButtonNavigate, SIGNAL(clicked(bool)), this, SLOT(actionNavigateClick()));
}

QString DialogCreateProject::getProjectDirectory()
{
	return lineEditDirectory->text();
}

QString DialogCreateProject::getProjectName()
{
	return lineEditName->text();
}

void DialogCreateProject::actionNavigateClick()
{
	QString projectdir = QFileDialog::getExistingDirectory(this, tr("Select a project dir"), QDir::homePath());
	if(projectdir.length())
	{
		lineEditDirectory->setText(projectdir);
	}
}
