#include "ProjectExplorer.h"

ProjectExplorer::ProjectExplorer(QWidget *parent) : QDockWidget(parent)
{
	m_TreeView = new QTreeView(this);
	setWindowTitle(tr("ProjectExplorer"));
	setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	setWidget(m_TreeView);
}
