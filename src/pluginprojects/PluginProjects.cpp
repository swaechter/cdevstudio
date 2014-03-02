#include "PluginProjects.h"

PluginProjects::PluginProjects()
{

}

PluginProjects::~PluginProjects()
{

}

void PluginProjects::init(CDevStudioPlatformPlugin* platformplugin)
{

}

QString PluginProjects::getPluginName()
{
    return QString(tr("Projects"));
}

QString PluginProjects::getPluginVersion()
{
    return QString(tr("0.0.6"));
}

QString PluginProjects::getPluginDescription()
{
    return QString(tr("PluginProjects provides some basic project templates"));
}

QStringList PluginProjects::getPluginDependencies()
{
    return QStringList();
}
