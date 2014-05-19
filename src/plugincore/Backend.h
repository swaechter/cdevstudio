#ifndef BACKEND_H
#define BACKEND_H

#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>

#include "PluginCoreExport.h"

class PLUGINCORE_EXPORT Backend
{
public:
	void createDirectory(QString directorypath);
	bool createFile(QString filepath);
	bool deleteFile(QString filepath);
	bool writeFile(QString filepath, QString text);
	QString readFile(QString filepath);
	QString getDirectoryOfFile(QString filepath);
	QString getNameOfFile(QString filepath);
	QStringList getFilesInDirectory(QString directorypath);
};

#endif // BACKEND_H
