#include "CDevStudioProjectTemplate.h"

CDevStudioProjectTemplate::CDevStudioProjectTemplate(QString name, QString description, QStringList files)
{
	dataTemplateName = name;
	dataTemplateDescription = description;
	dataTemplateFiles = files;
}

QString CDevStudioProjectTemplate::getTemplateName()
{
	return dataTemplateName;
}

QString CDevStudioProjectTemplate::getTemplateDescription()
{
	return dataTemplateDescription;
}

QStringList CDevStudioProjectTemplate::getTemplateFiles()
{
	return dataTemplateFiles;
}
