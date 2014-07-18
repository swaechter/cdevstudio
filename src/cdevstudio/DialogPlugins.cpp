#include "DialogPlugins.h"

DialogPlugins::DialogPlugins(QWidget *parent, QList<PluginContainer *> plugincontainers) : QDialog(parent)
{
	setupUi(this);
}
