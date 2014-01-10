#include "Utils.h"

QString Utils::getResourceText(const QString &resourcefile)
{
	QFile file(resourcefile);
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

QIcon Utils::getResourceIcon(const QString &resourcefile)
{
	return QIcon(resourcefile);
}
