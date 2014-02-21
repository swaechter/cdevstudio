#ifndef CDEVSTUDIOBACKEND_H
#define CDEVSTUDIOBACKEND_H

#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>

#include "CDevStudioPlatformExport.h"

class CDEVSTUDIOPLATFORM_API CDevStudioBackend
{
public:
	void createDirectory(const QString &directorypath);
	bool createFile(const QString &filepath);
	bool deleteFile(const QString &filepath);
	bool writeFile(const QString &filepath, const QString &text);
	QString readFile(const QString &filepath);
	QString getDirectoryOfFile(const QString &filepath);
	QString getNameOfFile(const QString &filepath);
	QStringList getFilesInDirectory(const QString &directorypath);
	QStringList getTranslationFiles();
};

#endif // CDEVSTUDIOBACKEND_H
