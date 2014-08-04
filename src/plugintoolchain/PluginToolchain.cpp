#include "PluginToolchain.h"

PluginToolchain::PluginToolchain()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindowManager()->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
}

PluginToolchain::~PluginToolchain()
{
}
