#include "DialogHelp.h"

DialogHelp::DialogHelp(QWidget *parent) : QDialog(parent)
{
	QTextBrowser *textbrowser = new QTextBrowser(this);
	QDialogButtonBox *buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok, Qt::Horizontal, this);
	QGridLayout *gridlayout = new QGridLayout(this);
	
	gridlayout->addWidget(textbrowser, 0, 0, 1, 1);
	gridlayout->addWidget(buttonbox, 1, 0, 1, 1);
	setLayout(gridlayout);
	
	connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
	
	setMinimumSize(500, 400);
	setWindowTitle(tr("Help"));
}
