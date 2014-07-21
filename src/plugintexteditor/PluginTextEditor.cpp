#include "PluginTextEditor.h"

PluginTextEditor::PluginTextEditor()
{
	Settings *settings = IPlatform::getInstance()->getWindowManager()->getWindow()->getSettingsDialog();
	PluginPage *pluginpage = new PluginPage(settings);
	settings->addSettingsPage(pluginpage);
}

PluginTextEditor::~PluginTextEditor()
{
}
