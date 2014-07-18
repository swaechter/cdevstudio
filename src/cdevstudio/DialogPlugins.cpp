#include "DialogPlugins.h"

DialogPlugins::DialogPlugins(QWidget *parent, QList<PluginContainer *> plugincontainers) : QDialog(parent)
{
	setupUi(this);
	
	foreach(PluginContainer *plugincontainer, plugincontainers)
	{
		int rows = tableWidgetPlugins->rowCount();
		tableWidgetPlugins->setRowCount(rows + 1);
		tableWidgetPlugins->setItem(rows, 0, new QTableWidgetItem(plugincontainer->getName()));
		tableWidgetPlugins->setItem(rows, 1, new QTableWidgetItem(plugincontainer->getDescription()));
	}
}