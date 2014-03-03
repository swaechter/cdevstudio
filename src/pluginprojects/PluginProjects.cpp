#include "PluginProjects.h"

PluginProjects::PluginProjects()
{

}

PluginProjects::~PluginProjects()
{

}

void PluginProjects::init(CDevStudioPlatformPlugin* platformplugin)
{
	CDevStudioProjectTemplate templateempty(tr("Empty Project"), tr("An empty project"), QStringList());
	CDevStudioProjectTemplate templatec(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c");
	CDevStudioProjectTemplate templatecplusplus(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp");
	
	platformplugin->addProjectTemplate(templateempty);
	platformplugin->addProjectTemplate(templatec);
	platformplugin->addProjectTemplate(templatecplusplus);
}

QString PluginProjects::getPluginName()
{
    return QString(tr("Projects"));
}

QString PluginProjects::getPluginVersion()
{
    return QString(tr("0.0.7"));
}

QString PluginProjects::getPluginDescription()
{
    return QString(tr("PluginProjects provides some basic project templates"));
}

QStringList PluginProjects::getPluginDependencies()
{
    return QStringList();
}
