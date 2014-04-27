#ifndef BACKEND_H
#define BACKEND_H

#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>
#include <QtCore/QPluginLoader>

namespace Backend
{
	QStringList getPluginDirectories();
	QStringList getPluginFilter();
	void createDirectory(QString directorypath);
	bool createFile(QString filepath);
	bool deleteFile(QString filepath);
	bool writeFile(QString filepath, QString text);
	QString readFile(QString filepath);
	QString getDirectoryOfFile(QString filepath);
	QString getNameOfFile(QString filepath);
	QStringList getFilesInDirectory(QString directorypath);
	QStringList getTranslationFiles();
}

#endif // BACKEND_H
