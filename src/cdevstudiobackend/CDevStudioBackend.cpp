#include "CDevStudioBackend.h"

struct CDevStudioBackend::Implementation
{
};

CDevStudioBackend::CDevStudioBackend() : QObject()
{
	implementation = new Implementation();
}

CDevStudioBackend::~CDevStudioBackend()
{
	delete implementation;
}

void CDevStudioBackend::createDirectory(const QString &directorypath)
{
	QDir directory(directorypath);
	if(!directory.exists())
	{
		directory.mkpath(directorypath);
	}
}

bool CDevStudioBackend::createFile(const QString &filepath)
{
	return writeFile(filepath, QString());
}

bool CDevStudioBackend::deleteFile(const QString &filepath)
{
	QFile file(filepath);
	if(file.exists())
	{
		file.remove();
		return true;
	}
	else
	{
		return false;
	}
}

bool CDevStudioBackend::writeFile(const QString &filepath, const QString &text)
{
	QFile file(filepath);
	if(file.open(QFile::WriteOnly))
	{
		QTextStream stream(&file);
		stream << text;
		file.close();
		return true;
	}
	else
	{
		return false;
	}
}

QString CDevStudioBackend::readFile(const QString &filepath)
{
	QFile file(filepath);
	if(file.open(QFile::ReadOnly))
	{
		QTextStream stream(&file);
		QString text = stream.readAll();
		file.close();
		return text;
	}
	else
	{
		return QString();
	}
}

QString CDevStudioBackend::getDirectoryOfFile(const QString &filepath)
{
	QFileInfo fileinfo(filepath);
	return fileinfo.absolutePath();
}

QStringList CDevStudioBackend::getFilesInDirectory(const QString &directorypath)
{
	QStringList files;
	QDir directory(directorypath);
	if(directory.exists())
	{
		files = directory.entryList();
	}
	return files;
}

QStringList CDevStudioBackend::getTranslationDirectories()
{
	QStringList directories = QStandardPaths::standardLocations(QStandardPaths::DataLocation);
	directories.removeDuplicates();
	
	foreach(QString directory, directories)
	{
		QString newdirectory = directory.append(QString("/translation"));
		directories.removeOne(newdirectory);
		directories.append(newdirectory);
	}
	
	QString windowsprogramfiles = qgetenv("PROGRAMFILES");
	if(windowsprogramfiles.length() != 0)
	{
		windowsprogramfiles = windowsprogramfiles.append("/cdevstudio/share/cdevstudio/translation");
		directories.append(windowsprogramfiles);
	}
	
	return directories;
}
