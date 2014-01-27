#ifndef CDEVSTUDIOBACKEND_H
#define CDEVSTUDIOBACKEND_H

#include <QtCore/QObject>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>

#include "CDevStudioBackendExport.h"

class CDEVSTUDIOBACKEND_API CDevStudioBackend : public QObject
{
	Q_OBJECT
	
public:
	CDevStudioBackend();
	~CDevStudioBackend();
	void createDirectory(const QString &directorypath);
	bool createFile(const QString &filepath);
	bool deleteFile(const QString &filepath);
	bool writeFile(const QString &filepath, const QString &text);
	QString readFile(const QString &filepath);
	QString getDirectoryOfFile(const QString &filepath);
	QString getNameOfFile(const QString &filepath);
	QStringList getFilesInDirectory(const QString &directorypath);
	QStringList getTranslationFiles();
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOBACKEND_H
