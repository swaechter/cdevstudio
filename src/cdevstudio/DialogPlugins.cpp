#include "DialogPlugins.h"

DialogPlugins::DialogPlugins(QList<ICDevStudioPlugin *> plugins, QWidget *parent): QDialog(parent)
{
	setupUi(this);
	
	foreach(ICDevStudioPlugin *plugin, plugins)
	{
		int rows = tableWidget->rowCount();
		tableWidget->setRowCount(rows + 1);
		tableWidget->setItem(rows, 0, new QTableWidgetItem(plugin->getPluginName()));
		tableWidget->setItem(rows, 1, new QTableWidgetItem(plugin->getPluginVersion()));
		tableWidget->setItem(rows, 2, new QTableWidgetItem(plugin->getPluginDescription()));
	}
}
