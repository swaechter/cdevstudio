#include "DialogSettings.h"

DialogSettings::DialogSettings(QWidget *parent) : QDialog(parent)
{
	QTabWidget *tabwidget = new QTabWidget(this);
	QDialogButtonBox *buttonbox = new QDialogButtonBox(QDialogButtonBox::Cancel | QDialogButtonBox::Save, Qt::Horizontal, this);
	QGridLayout *gridlayout = new QGridLayout(this);
	
	gridlayout->addWidget(tabwidget, 0, 0, 1, 1);
	gridlayout->addWidget(buttonbox, 1, 0, 1, 1);
	setLayout(gridlayout);
	
	QWidget *widgetgeneral = new QWidget(tabwidget);
	tabwidget->addTab(widgetgeneral, tr("General"));
	
	connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
	
	setMinimumSize(500, 400);
	setWindowTitle(tr("Settings"));
}
