#ifndef PLUGINPROJECTEXPLORER_H
#define PLUGINPROJECTEXPLORER_H

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QFileSystemModel>
#include <QtCore/QObject>
#include <cdevstudioplatform/interfaces/IPlugin.h>
#include <cdevstudioplatform/interfaces/IPlatform.h>
#include <cdevstudioplatform/ProjectManager.h>
#include <cdevstudioplatform/ProjectTemplate.h>
#include <cdevstudioplatform/Project.h>

#include "PluginProjectExplorerExport.h"

class PLUGINPROJECTEXPLORER_API PluginProjectExplorer : public QObject, private IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin")
	
public:
	PluginProjectExplorer();
	~PluginProjectExplorer();
	QString getName();
	QString getVersion();
	QString getDescription();
	
private:
	QDockWidget *m_DockWidget;
	QTreeView *m_TreeView;
	QFileSystemModel *m_FileSystemModel;
	Project *m_Project;
	
	void hideColumns();
	
private slots:
	void openProject(Project *project);
	void closeProject(Project *project);
};

#endif // PLUGINPROJECTEXPLORER_H
