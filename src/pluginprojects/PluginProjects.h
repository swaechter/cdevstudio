#ifndef PLUGINPROJECTS_H
#define PLUGINPROJECTS_H

#include <QtCore/QObject>
#include <cdevstudioplatform/CDevStudioPlatformPlugin.h>
#include <cdevstudioplatform/ICDevStudioPlugin.h>

#include "PluginProjectsExport.h"

class PLUGINPROJECTS_API PluginProjects : public QObject, private ICDevStudioPlugin
{
        Q_OBJECT
        Q_INTERFACES(ICDevStudioPlugin)
        Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.ICDevStudioPlugin")
        
public:
        PluginProjects();
        ~PluginProjects();
        void init(CDevStudioPlatformPlugin *platformplugin);
        QString getPluginName();
        QString getPluginVersion();
        QString getPluginDescription();
        QStringList getPluginDependencies();
};

#endif // PLUGINPROJECTS_H
