#include "CDevStudioProjectTemplate.h"

CDevStudioProjectTemplate::CDevStudioProjectTemplate(QString name, QString description, QStringList files)
{
	m_TemplateName = name;
	m_TemplateDescription = description;
	m_TemplateFiles = files;
}

QString CDevStudioProjectTemplate::getTemplateName()
{
	return m_TemplateName;
}

QString CDevStudioProjectTemplate::getTemplateDescription()
{
	return m_TemplateDescription;
}

QStringList CDevStudioProjectTemplate::getTemplateFiles()
{
	return m_TemplateFiles;
}
