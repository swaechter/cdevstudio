#include "Backend.h"

QStringList Backend::getPluginDirectories()
{
	QStringList directories;
	
#ifdef Q_OS_WIN
	directories << "C:/Users/swaechter/Downloads/cdevstudio/build/src/pluginprojects/";
	directories << "C:/Users/swaechter/Downloads/cdevstudio/build/src/pluginprojectexplorer/";
	directories << "C:/Users/swaechter/Downloads/cdevstudio/build/src/plugintexteditor/";
#else
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojects/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectexplorer/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/plugintexteditor/";
#endif
	
	return directories;
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
