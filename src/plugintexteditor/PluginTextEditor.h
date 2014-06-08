#ifndef PLUGINTEXTEDITOR_H
#define PLUGINTEXTEDITOR_H

#include <QtCore/QObject>
#include <cdevstudioplatform/PluginPlatform.h>
#include <cdevstudioplatform/Plugin.h>

#include "PluginTextEditorExport.h"

class PLUGINTEXTEDITOR_EXPORT PluginTextEditor : public Plugin
{
	Q_OBJECT
	Q_INTERFACES(Plugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.Plugin")
	
public:
	PluginTextEditor();
	~PluginTextEditor();
	QString getName();
	QString getVersion();
	QString getDescription();
};

#endif // PLUGINTEXTEDITOR_H
