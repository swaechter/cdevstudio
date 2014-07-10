#ifndef PLUGINPROJECTEXPLORER_H
#define PLUGINPROJECTEXPLORER_H

#include <QtWidgets/QAction>
#include <QtCore/QObject>
#include <cdevstudioplatform/IPlatform.h>
#include <cdevstudioplatform/IPlugin.h>
#include <cdevstudioplatform/Project.h>
#include <cdevstudioplatform/WindowManager.h>
#include <cdevstudioplatform/Window.h>

#include "PluginProjectExplorerExport.h"
#include "ProjectExplorer.h"

class PLUGINPROJECTEXPLORER_EXPORT PluginProjectExplorer : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin" FILE "PluginProjectExplorer.json")
	
public:
	PluginProjectExplorer();
	~PluginProjectExplorer();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	ProjectExplorer *m_ProjectExplorer;
	QAction *m_ActionProjectExplorer;
	
private slots:
	void actionProjectExplorerTriggered();
	void projectOpen();
	void projectClose();
	void fileOpen(QString file);
};

#endif // PLUGINPROJECTEXPLORER_H
