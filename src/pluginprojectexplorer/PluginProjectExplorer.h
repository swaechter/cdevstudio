#ifndef PLUGINPROJECTEXPLORER_H
#define PLUGINPROJECTEXPLORER_H

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QFileSystemModel>
#include <QtCore/QObject>
#include <cdevstudioplatform/CDevStudioPlatformPlugin.h>
#include <cdevstudioplatform/CDevStudioProjectManager.h>
#include <cdevstudioplatform/CDevStudioProject.h>
#include <cdevstudioplatform/ICDevStudioPlugin.h>

#include "PluginProjectExplorerExport.h"

class PLUGINPROJECTEXPLORER_API PluginProjectExplorer : public QObject, private ICDevStudioPlugin
{
	Q_OBJECT
	Q_INTERFACES(ICDevStudioPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.ICDevStudioPlugin")
	
public:
	PluginProjectExplorer();
	~PluginProjectExplorer();
	void init(CDevStudioPlatformPlugin *platformplugin);
	QString getPluginName();
	QString getPluginVersion();
	QString getPluginDescription();
	QStringList getPluginDependencies();
	
private:
	QDockWidget *m_DockWidget;
	QTreeView *m_TreeView;
	QFileSystemModel *m_FileSystemModel;
	CDevStudioProject *m_Project;
	
	void hideColumns();
	
private slots:
	void openProject(CDevStudioProject *project);
	void closeProject(CDevStudioProject *project);
};

#endif // PLUGINPROJECTEXPLORER_H
