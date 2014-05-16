#include "PluginProjectData.h"

PluginProjectData::PluginProjectData()
{
	m_PluginCore = (PluginCore *) IPlatform::getInstance()->getPluginManager()->getPlugin("Core");
	m_PluginProjects = (PluginProjects *) IPlatform::getInstance()->getPluginManager()->getPlugin("Projects");
	m_PluginProjects->addTemplate(tr("Empty Project"), tr("An empty project"), QStringList());
	m_PluginProjects->addTemplate(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c");
	m_PluginProjects->addTemplate(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp");
	qDebug() << "PluginProjectData";
}

PluginProjectData::~PluginProjectData()
{

}

QString PluginProjectData::getName()
{
	return QString(tr("ProjectData"));
}

QString PluginProjectData::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjectData::getDescription()
{
	return QString(tr("PluginProjectData provides several templates"));
}
