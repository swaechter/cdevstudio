#ifndef CDEVSTUDIOPROJECTTEMPLATE_H
#define CDEVSTUDIOPROJECTTEMPLATE_H

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QFile>

class CDevStudioProjectTemplate
{
public:
	CDevStudioProjectTemplate(QString name, QString description, QStringList files);
	QString getTemplateName();
	QString getTemplateDescription();
	QStringList getTemplateFiles();
	
private:
	QString m_TemplateName;
	QString m_TemplateDescription;
	QStringList m_TemplateFiles;
};

#endif // CDEVSTUDIOPROJECTTEMPLATE_H
