#include "DialogPlugins.h"

DialogPlugins::DialogPlugins(QList<IPlugin *> plugins, QWidget *parent): QDialog(parent)
{
	setupUi(this);
	
	foreach(IPlugin *plugin, plugins)
	{
		int rows = tableWidget->rowCount();
		tableWidget->setRowCount(rows + 1);
		tableWidget->setItem(rows, 0, new QTableWidgetItem(plugin->getName()));
		tableWidget->setItem(rows, 1, new QTableWidgetItem(plugin->getVersion()));
		tableWidget->setItem(rows, 2, new QTableWidgetItem(plugin->getDescription()));
	}
}
