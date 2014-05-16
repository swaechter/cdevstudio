#include "PluginSettings.h"

PluginSettings::PluginSettings()
{
	m_PluginCore = (PluginCore *) IPlatform::getInstance()->getPluginManager()->getPlugin("Core");
	
	m_Settings = new QAction(tr("Settings"), m_PluginCore->getWindow()->getSettingsMenu());
	
	m_PluginCore->getWindow()->getSettingsMenu()->addAction(m_Settings);
	
	connect(m_Settings, SIGNAL(triggered(bool)), this, SLOT(actionSettings()));
	
	qDebug() << "PluginSettings";
}

PluginSettings::~PluginSettings()
{
}

QString PluginSettings::getName()
{
	return QString(tr("Settings"));
}

QString PluginSettings::getVersion()
{
	return QString(tr("0.0.7"));
}

QString PluginSettings::getDescription()
{
	return QString(tr("PluginSettings provides a settings system"));
}

void PluginSettings::actionSettings()
{
	DialogSettings *dialog = new DialogSettings(m_PluginCore->getWindow());
	if(dialog->exec() == QDialog::Accepted)
	{
	}
}
