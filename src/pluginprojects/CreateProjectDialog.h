#ifndef CREATEPROJECTDIALOG_H
#define CREATEPROJECTDIALOG_H

#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QGridLayout>
#include <QtCore/QList>

#include "ProjectTemplate.h"

class CreateProjectDialog : public QWizard
{
	Q_OBJECT
	
public:
	CreateProjectDialog(QList<ProjectTemplate> templates, QWidget *parent);
	QString getTemplateName();
	QString getProjectName();
	QString getProjectLocation();
	
private:
	QComboBox *m_Template;
	QLineEdit *m_Name;
	QLineEdit *m_Location;
	
	QWizardPage *getWelcomePage();
	QWizardPage *getTemplatePage(QList<ProjectTemplate> templates);
	QWizardPage *getNamePage();
	QWizardPage *getLocationPage();
	QWizardPage *getFinishPage();
};

#endif // CREATEPROJECTDIALOG_H
