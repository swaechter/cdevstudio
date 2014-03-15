#ifndef CDEVSTUDIOBACKEND_H
#define CDEVSTUDIOBACKEND_H

#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>
#include <QtCore/QPluginLoader>

#include "CDevStudioPlatformExport.h"

class CDEVSTUDIOPLATFORM_API CDevStudioBackend
{
public:
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
};

#endif // CDEVSTUDIOBACKEND_H
