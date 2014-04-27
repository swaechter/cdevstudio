#include "PluginProjects.h"

PluginProjects::PluginProjects()
{
	ProjectManager *manager = IPlatform::getInstance()->getProjectManager();
	manager->addProjectTemplate(tr("Empty Project"), tr("An empty project"), QStringList());
	manager->addProjectTemplate(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c");
	manager->addProjectTemplate(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp");
}

PluginProjects::~PluginProjects()
{
}

QString PluginProjects::getName()
{
	return QString(tr("Projects"));
}

QString PluginProjects::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjects::getDescription()
{
	return QString(tr("PluginProjects provides some basic project templates"));
}
