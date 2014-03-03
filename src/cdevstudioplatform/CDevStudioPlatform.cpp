#include "CDevStudioPlatform.h"


CDevStudioPlatform::CDevStudioPlatform(CDevStudioWindow *window) : QObject()
{
	cdevstudioWindow = window;
	cdevstudioBackend = new CDevStudioBackend();
	
	foreach(QString path, cdevstudioBackend->getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(cdevstudioBackend->getPluginFilter());
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file, this);
			QObject *object = loader.instance();
			if(object != nullptr)
			{
				ICDevStudioPlugin *plugin = qobject_cast<ICDevStudioPlugin *>(object);
				if(plugin != nullptr)
				{
					cdevstudioPlugins.append(plugin);
					qDebug() << "CDevStudioPlatform loaded:" << plugin->getPluginName();
				}
				else
				{
					qDebug() << "CDevStudioPlatform: Cannot cast plugin" << file;
				}
			}
			else
			{
				qDebug() << "CDevStudioPlatform: Loader error:" << loader.errorString();
			}
		}
	}
	
	cdevstudioPlatformPlugins = new CDevStudioPlatformPlugin(cdevstudioWindow, cdevstudioPlugins, cdevstudioBackend);
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	qDeleteAll<>(cdevstudioPlugins);
	delete cdevstudioPlatformPlugins;
	delete cdevstudioBackend;
}

void CDevStudioPlatform::initPlugins()
{
	foreach(ICDevStudioPlugin *plugin, cdevstudioPlugins)
	{
		plugin->init(cdevstudioPlatformPlugins);
	}
}

CDevStudioWindow *CDevStudioPlatform::getWindow()
{
	return cdevstudioWindow;
}

QList<ICDevStudioPlugin *> CDevStudioPlatform::getPlugins()
{
	return cdevstudioPlugins;
}
