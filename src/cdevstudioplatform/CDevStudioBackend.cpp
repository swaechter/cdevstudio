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

QList<ICDevStudioPlugin *> CDevStudioBackend::loadPlugins()
{
	QList<ICDevStudioPlugin *> plugins;
	foreach(QString path, getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(getPluginFilter());
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file);
			QObject *object = loader.instance();
			if(object != nullptr)
			{
				ICDevStudioPlugin *plugin = qobject_cast<ICDevStudioPlugin *>(object);
				if(plugin != nullptr)
				{
					plugins.append(plugin);
				}
			}
		}
	}
	return plugins;
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

QString CDevStudioBackend::getNameOfFile(const QString &filepath)
{
	QFileInfo fileinfo(filepath);
	return fileinfo.fileName();
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
