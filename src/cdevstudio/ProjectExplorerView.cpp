#include "ProjectExplorerView.h"

ProjectExplorerView::ProjectExplorerView(QWidget *parent) : QTreeView(parent)
{
	header()->hide();
}

void ProjectExplorerView::updateView()
{
	hideColumn(1);
	hideColumn(2);
	hideColumn(3);
}
