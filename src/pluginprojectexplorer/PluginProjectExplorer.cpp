#include "PluginProjectExplorer.h"

PluginProjectExplorer::PluginProjectExplorer()
{

}

PluginProjectExplorer::~PluginProjectExplorer()
{

}

void PluginProjectExplorer::init(CDevStudioPlatformPlugin* platformplugin)
{
	m_DockWidget = new QDockWidget(tr("Project Explorer"), platformplugin->getWindowManager()->getWindow());
	m_DockWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	platformplugin->getWindowManager()->getWindow()->addDockWidget(Qt::LeftDockWidgetArea, m_DockWidget);
	
	m_TreeView = new QTreeView(m_DockWidget);
	m_FileSystemModel = new QFileSystemModel(m_TreeView);
	
	m_TreeView->setModel(m_FileSystemModel);
	m_TreeView->header()->hide();
	m_DockWidget->setWidget(m_TreeView);
	hideColumns();
	
	connect(platformplugin->getProjectManager(), SIGNAL(projectOpen(CDevStudioProject*)), this, SLOT(openProject(CDevStudioProject*)));
	connect(platformplugin->getProjectManager(), SIGNAL(projectClose(CDevStudioProject*)), this, SLOT(closeProject(CDevStudioProject*)));
}

QString PluginProjectExplorer::getPluginName()
{
	return QString(tr("ProjectExplorer"));
}

QString PluginProjectExplorer::getPluginVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginProjectExplorer::getPluginDescription()
{
	return QString(tr("PluginProjectExplorer provides a basic project view"));
}

QStringList PluginProjectExplorer::getPluginDependencies()
{
	return QStringList();
}

void PluginProjectExplorer::openProject(CDevStudioProject *project)
{
	m_FileSystemModel->setRootPath(project->getProjectDirectory());
	m_TreeView->setModel(m_FileSystemModel);
	m_TreeView->setRootIndex(m_FileSystemModel->index(project->getProjectDirectory()));
	hideColumns();
}

void PluginProjectExplorer::closeProject(CDevStudioProject *project)
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
