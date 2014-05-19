#include "DialogAbout.h"

DialogAbout::DialogAbout(QString abouttext, QString licensetext, QString thankstotext, QWidget *parent) : QDialog(parent)
{
	QTabWidget *tabwidget = new QTabWidget(this);
	QDialogButtonBox *buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok, Qt::Horizontal, this);
	QGridLayout *gridlayout = new QGridLayout(this);
	
	gridlayout->addWidget(tabwidget, 0, 0, 1, 1);
	gridlayout->addWidget(buttonbox, 1, 0, 1, 1);
	setLayout(gridlayout);
	
	QTextBrowser *textbrowserabout = new QTextBrowser(tabwidget);
	QTextBrowser *textbrowserlicense = new QTextBrowser(tabwidget);
	QTextBrowser *textbrowserthanksto = new QTextBrowser(tabwidget);
	
	textbrowserabout->setText(abouttext);
	textbrowserlicense->setText(licensetext);
	textbrowserthanksto->setText(thankstotext);
	
	tabwidget->addTab(textbrowserabout, tr("About"));
	tabwidget->addTab(textbrowserlicense, tr("License"));
	tabwidget->addTab(textbrowserthanksto, tr("Thanks To"));
	
	connect(buttonbox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonbox, SIGNAL(rejected()), this, SLOT(reject()));
	
	setMinimumSize(500, 400);
	setWindowTitle(tr("About"));
}
