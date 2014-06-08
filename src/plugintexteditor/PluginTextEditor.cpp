#include "PluginTextEditor.h"

PluginTextEditor::PluginTextEditor()
{
}

PluginTextEditor::~PluginTextEditor()
{
}

QString PluginTextEditor::getName()
{
	return QString(tr("TextEditor"));
}

QString PluginTextEditor::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginTextEditor::getDescription()
{
	return QString(tr("PluginTextEditor provides the text editor"));
}
