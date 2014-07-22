#include "CreateProjectDialog.h"

CreateProjectDialog::CreateProjectDialog(QList<ProjectTemplate> templates, QWidget *parent) : QWizard(parent)
{
	addPage(getWelcomePage());
	addPage(getTemplatePage(templates));
	addPage(getNamePage());
	addPage(getLocationPage());
	addPage(getFinishPage());
	
	setWindowTitle(tr("Create Project"));
}

QString CreateProjectDialog::getTemplateName()
{
	return m_Template->currentText();
}

QString CreateProjectDialog::getProjectName()
{
	return m_Name->text();
}

QString CreateProjectDialog::getProjectLocation()
{
	return m_Location->text();
}

QWizardPage *CreateProjectDialog::getWelcomePage()
{
	QWizardPage *wizardpage = new QWizardPage(this);
	wizardpage->setTitle("Create Project");
	
	QLabel *label = new QLabel(tr("This wizard will guide you through the project creation."), wizardpage);
	QGridLayout *gridlayout = new QGridLayout(wizardpage);
	
	gridlayout->addWidget(label, 0, 0, 1, 1);
	
	wizardpage->setLayout(gridlayout);
	
	return wizardpage;
}

QWizardPage *CreateProjectDialog::getTemplatePage(QList<ProjectTemplate> templates)
{
	QWizardPage *wizardpage = new QWizardPage(this);
	wizardpage->setTitle("Select a Template");
	
	QLabel *label = new QLabel(tr("Please select a project template from the list."), wizardpage);
	m_Template = new QComboBox(wizardpage);
	QGridLayout *gridlayout = new QGridLayout(wizardpage);
	
	foreach(ProjectTemplate projecttemplate, templates)
	{
		m_Template->addItem(projecttemplate.getName());
	}
	
	gridlayout->addWidget(label, 0, 0, 1, 1);
	gridlayout->addWidget(m_Template, 1, 0, 1, 1);
	
	wizardpage->setLayout(gridlayout);
	
	return wizardpage;
}

QWizardPage *CreateProjectDialog::getNamePage()
{
	QWizardPage *wizardpage = new QWizardPage(this);
	wizardpage->setTitle("Select a Name");
	
	QLabel *label = new QLabel(tr("Please insert a name for your project."), wizardpage);
	m_Name = new QLineEdit(wizardpage);
	QGridLayout *gridlayout = new QGridLayout(wizardpage);
	
	gridlayout->addWidget(label, 0, 0, 1, 1);
	gridlayout->addWidget(m_Name, 1, 0, 1, 1);
	
	wizardpage->setLayout(gridlayout);
	
	return wizardpage;
}

QWizardPage *CreateProjectDialog::getLocationPage()
{
	QWizardPage *wizardpage = new QWizardPage(this);
	wizardpage->setTitle("Select a Location");
	
	QLabel *label = new QLabel(tr("Please select a location for the project."), wizardpage);
	m_Location = new QLineEdit(wizardpage);
	QGridLayout *gridlayout = new QGridLayout(wizardpage);
	
	gridlayout->addWidget(label, 0, 0, 1, 1);
	gridlayout->addWidget(m_Location, 1, 0, 1, 1);
	
	wizardpage->setLayout(gridlayout);
	
	return wizardpage;
}

QWizardPage *CreateProjectDialog::getFinishPage()
{
	QWizardPage *wizardpage = new QWizardPage(this);
	wizardpage->setTitle("Create Project");
	
	QLabel *label = new QLabel(tr("The project creation is nearly finished. Please continue to finish the new project."), wizardpage);
	QGridLayout *gridlayout = new QGridLayout(wizardpage);
	
	gridlayout->addWidget(label, 0, 0, 1, 1);
	
	wizardpage->setLayout(gridlayout);
	
	return wizardpage;
}
