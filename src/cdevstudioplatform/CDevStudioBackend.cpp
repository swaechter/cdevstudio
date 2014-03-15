#include "CDevStudioBackend.h"


QStringList CDevStudioBackend::getPluginDirectories()
{
	QStringList directories;
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginhelp/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojects/";
	return directories;
}

QStringList CDevStudioBackend::getPluginFilter()
{
	return QStringList() << "*plugin*.so" << "*plugin*.dll";
}

void CDevStudioBackend::createDirectory(QString directorypath)
{
	QDir directory(directorypath);
	if(!directory.exists())
	{
		directory.mkpath(directorypath);
	}
}

bool CDevStudioBackend::createFile(QString filepath)
{
	return writeFile(filepath, QString());
}

bool CDevStudioBackend::deleteFile(QString filepath)
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

bool CDevStudioBackend::writeFile(QString filepath, QString text)
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

QString CDevStudioBackend::readFile(QString filepath)
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

QString CDevStudioBackend::getDirectoryOfFile(QString filepath)
{
	QFileInfo fileinfo(filepath);
	return fileinfo.absolutePath();
}

QString CDevStudioBackend::getNameOfFile(QString filepath)
{
	QFileInfo fileinfo(filepath);
	return fileinfo.fileName();
}

QStringList CDevStudioBackend::getFilesInDirectory(QString directorypath)
{
	QStringList files;
	QDir directory(directorypath);
	if(directory.exists())
	{
		files = directory.entryList();
	}
	return files;
}

QStringList CDevStudioBackend::getTranslationFiles()
{
	QString path(":/data/translation/");
	QStringList translations;
	QStringList files = QDir(path).entryList();
	foreach(QString file, files)
	{
		translations.append(file.prepend(path));
	}
	return translations;
}
