#include "CDevStudioPlatform.h"

struct CDevStudioPlatform::Implementation
{
	CDevStudioWindow *window;
	CDevStudioPlatformPlugin *platformplugin;
	CDevStudioBackend *backend;
	QList<ICDevStudioPlugin *> plugins;
};

CDevStudioPlatform::CDevStudioPlatform(CDevStudioWindow *window) : QObject()
{
	implementation = new Implementation();
	implementation->window = window;
	implementation->backend = new CDevStudioBackend();
	
	foreach(QString path, implementation->backend->getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(implementation->backend->getPluginFilter());
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file, this);
			QObject *object = loader.instance();
			if(object != nullptr)
			{
				ICDevStudioPlugin *plugin = qobject_cast<ICDevStudioPlugin *>(object);
				if(plugin != nullptr)
				{
					implementation->plugins.append(plugin);
					qDebug() << "CDevStudioPlatform loaed:" << plugin->getPluginName();
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
	
	implementation->platformplugin = new CDevStudioPlatformPlugin(implementation->window, implementation->plugins, implementation->backend);
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	qDeleteAll<>(implementation->plugins);
	delete implementation->platformplugin;
	delete implementation->backend;
	delete implementation;
}

void CDevStudioPlatform::initPlugins()
{
	foreach(ICDevStudioPlugin *plugin, implementation->plugins)
	{
		plugin->init(implementation->platformplugin);
	}
}


CDevStudioPlatformPlugin *CDevStudioPlatform::getPluginPlatform()
{
	return implementation->platformplugin;
}
