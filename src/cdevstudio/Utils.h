#ifndef UTILS_H
#define UTILS_H

#include <QtGui/QIcon>
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

class Utils
{
public:
	static QString getResourceText(const QString &resourcefile);
	static QIcon getResourceIcon(const QString &resourcefile);
};

#endif // UTILS_H
