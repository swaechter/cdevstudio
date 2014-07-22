#ifndef PLUGINTEXTEDITOR_H
#define PLUGINTEXTEDITOR_H

#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPlugin.h>

#include "PluginTextEditorExport.h"
#include "PluginPage.h"

class PLUGINTEXTEDITOR_EXPORT PluginTextEditor : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin" FILE "PluginTextEditor.json")
	
public:
	PluginTextEditor();
	~PluginTextEditor();
	
private slots:
	void openFile(QString file);
	void closeFile(QString file);
	void closeFileRequest(QString file);
};

#endif // PLUGINTEXTEDITOR_H
