#include "PluginCore.h"

PluginCore::PluginCore()
{
	m_Window = new Window();
	m_Window->show();
	qDebug() << "PluginCore";
}

PluginCore::~PluginCore()
{
	delete m_Window;
}

QString PluginCore::getName()
{
	return QString(tr("Core"));
}

QString PluginCore::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginCore::getDescription()
{
	return QString(tr("PluginCore provides some a basic plugin framework"));
}

Window *PluginCore::getWindow()
{
	return m_Window;
}
