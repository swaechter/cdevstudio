#ifndef PROJECTEXPLORERVIEW_H
#define PROJECTEXPLORERVIEW_H

#include <QtWidgets/QTreeView>
#include <QtWidgets/QHeaderView>

class ProjectExplorerView : public QTreeView
{
	Q_OBJECT
	
public:
	ProjectExplorerView(QWidget *parent);
	void updateView();
};

#endif // PROJECTEXPLORERVIEW_H
