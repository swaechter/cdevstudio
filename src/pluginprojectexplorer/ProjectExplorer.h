#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QTreeView>

#include "PluginProjectExplorerExport.h"

class PLUGINPROJECTEXPLORER_EXPORT ProjectExplorer : public QDockWidget
{
	Q_OBJECT
	
public:
	ProjectExplorer(QWidget *parent);
	
private:
	QTreeView *m_TreeView;
};

#endif // PROJECTEXPLORER_H
