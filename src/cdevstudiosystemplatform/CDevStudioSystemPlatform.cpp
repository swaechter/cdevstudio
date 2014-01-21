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
	foreach(QString path, implementation->backend->getTranslationDirectories())
	{
		foreach(QString file, implementation->backend->getFilesInDirectory(path))
		{
			if(file.endsWith(QString(".qm")))
			{
				QStringList params = file.split(QString("."));
				QString locale = params.at(0);
				locale.remove(QString("translation_"));
				if(!locales.contains(locale))
				{
					locales.append(locale);
				}
			}
		}
	}
	return locales;
}

QString CDevStudioSystemPlatform::getLocalePath(const QString &locale)
{
	foreach(QString path, implementation->backend->getTranslationDirectories())
	{
		foreach(QString file, implementation->backend->getFilesInDirectory(path))
		{
			QString localefile = QString("translation_") + locale + QString(".qm");
			if(file.compare(localefile) == 0)
			{
				return path + QString("/") + localefile;
			}
		}
	}
	return QString();
}
