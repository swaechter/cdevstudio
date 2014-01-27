#include "CDevStudioSystemPlatform.h"

struct CDevStudioSystemPlatform::Implementation
{
	CDevStudioBackend *backend;
};

CDevStudioSystemPlatform::CDevStudioSystemPlatform() : QObject()
{
	implementation = new Implementation();
	implementation->backend = new CDevStudioBackend();
}

CDevStudioSystemPlatform::~CDevStudioSystemPlatform()
{
	delete implementation->backend;
	delete implementation;
}

QStringList CDevStudioSystemPlatform::getAvailableLocales()
{
	QStringList locales;
	foreach(QString filepath, implementation->backend->getTranslationFiles())
	{
		if(filepath.endsWith(QString(".qm")))
		{
			QString filename = implementation->backend->getNameOfFile(filepath);
			QStringList params = filename.split(QString("."));
			QString locale = params.at(0);
			locale = locale.remove(QString("translation_"));
			if(!locales.contains(locale))
			{
				locales.append(locale);
			}
		}
	}
	return locales;
}

QString CDevStudioSystemPlatform::getLocalePath(const QString &locale)
{
	foreach(QString filepath, implementation->backend->getTranslationFiles())
	{
		QString filename = QString("translation_") + locale + QString(".qm");
		if(filepath.endsWith(filename))
		{
			return filepath;
		}
	}
	return QString();
}
