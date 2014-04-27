#include "PluginProjectExplorer.h"

PluginProjectExplorer::PluginProjectExplorer()
{
	m_DockWidget = new QDockWidget(tr("Project Explorer"), IPlatform::getInstance()->getWindowManager()->getWindow());
	m_DockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	IPlatform::getInstance()->getWindowManager()->getWindow()->addDockWidget(Qt::LeftDockWidgetArea, m_DockWidget);
	
	m_TreeView = new QTreeView(m_DockWidget);
	m_FileSystemModel = new QFileSystemModel(m_TreeView);
	
	m_TreeView->setModel(m_FileSystemModel);
	m_TreeView->header()->hide();
	m_DockWidget->setWidget(m_TreeView);
	hideColumns();
	
	connect(IPlatform::getInstance()->getProjectManager(), SIGNAL(projectOpen(Project *)), this, SLOT(openProject(Project *)));
	connect(IPlatform::getInstance()->getProjectManager(), SIGNAL(projectClose(Project *)), this, SLOT(closeProject(Project *)));
}

PluginProjectExplorer::~PluginProjectExplorer()
{

}

QString PluginProjectExplorer::getName()
{
	return QString(tr("ProjectExplorer"));
}

QString PluginProjectExplorer::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjectExplorer::getDescription()
{
	return QString(tr("PluginProjectExplorer provides a basic project view"));
}

void PluginProjectExplorer::openProject(Project *project)
{
	m_FileSystemModel->setRootPath(project->getDirectory());
	m_TreeView->setModel(m_FileSystemModel);
	m_TreeView->setRootIndex(m_FileSystemModel->index(project->getDirectory()));
	hideColumns();
}

void PluginProjectExplorer::closeProject(Project *project)
{
	m_TreeView->setModel(nullptr);
}

void PluginProjectExplorer::hideColumns()
{
	m_TreeView->hideColumn(1);
	m_TreeView->hideColumn(2);
	m_TreeView->hideColumn(3);
	m_TreeView->hideColumn(4);
}
