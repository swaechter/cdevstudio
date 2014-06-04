#include "PluginPlatform.h"

PluginPlatform *PluginPlatform::m_PluginPlatform = nullptr;

PluginPlatform::PluginPlatform(QObject *parent) : QObject(parent)
{
	m_PluginPlatform = this;
}

PluginPlatform *PluginPlatform::getInstance()
{
	return m_PluginPlatform;
}
