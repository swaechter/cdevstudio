#include "PluginProjectExplorer.h"

PluginProjectExplorer::PluginProjectExplorer()
{
	PluginPlatform *pluginplatform = PluginPlatform::getInstance();
	Window *window = pluginplatform->getWindowManager()->getWindow();
	
	m_ActionProjectExplorer = new QAction(tr("Project Explorer"), window);
	m_ActionProjectExplorer->setCheckable(true);
	m_ActionProjectExplorer->setChecked(true);
	window->getMenu(View)->addAction(m_ActionProjectExplorer);
	
	m_ProjectExplorer = new ProjectExplorer(window);
	window->addDockWidget(Qt::LeftDockWidgetArea, m_ProjectExplorer);
	
	connect(m_ActionProjectExplorer, SIGNAL(triggered(bool)), this, SLOT(actionProjectExplorerTriggered()));
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

void PluginProjectExplorer::actionProjectExplorerTriggered()
{
	if(m_ActionProjectExplorer->isChecked())
	{
		m_ProjectExplorer->show();
	}
	else
	{
		m_ProjectExplorer->hide();
	}
}
