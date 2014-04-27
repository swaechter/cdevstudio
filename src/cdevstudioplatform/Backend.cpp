#include "Backend.h"

QStringList Backend::getPluginDirectories()
{
	QStringList directories;
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojects/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectexplorer/";
	return directories;
}

QStringList Backend::getPluginFilter()
{
	return QStringList() << "*plugin*.so" << "*plugin*.dll";
}

void Backend::createDirectory(QString directorypath)
{
	QDir directory(directorypath);
	if(!directory.exists())
	{
		directory.mkpath(directorypath);
	}
}

bool Backend::createFile(QString filepath)
{
	return writeFile(filepath, QString());
}

bool Backend::deleteFile(QString filepath)
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

bool Backend::writeFile(QString filepath, QString text)
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

QString Backend::readFile(QString filepath)
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

QString Backend::getDirectoryOfFile(QString filepath)
{
	QFileInfo fileinfo(filepath);
	return fileinfo.absolutePath();
}

QString Backend::getNameOfFile(QString filepath)
{
	QFileInfo fileinfo(filepath);
	return fileinfo.fileName();
}

QStringList Backend::getFilesInDirectory(QString directorypath)
{
	QStringList files;
	QDir directory(directorypath);
	if(directory.exists())
	{
		files = directory.entryList();
	}
	return files;
}

QStringList Backend::getTranslationFiles()
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
