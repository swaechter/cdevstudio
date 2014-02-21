#include "PluginHelp.h"

PluginHelp::PluginHelp()
{
	CDevStudioMenuBar *menubar = CDevStudioPlatform::getInstance()->getWindow()->getMenuBar();
	
	CDevStudioMenu *menuhelp = new CDevStudioMenu(tr("Help"), menubar);
	CDevStudioAction *actionhelp = new CDevStudioAction(tr("Help"), menuhelp);
	CDevStudioAction *actionabout = new CDevStudioAction(tr("About"), menuhelp);
	
	menuhelp->addAction(actionhelp);
	menuhelp->addAction(actionabout);
	
	menubar->addMenu(menuhelp);
	
	connect(actionhelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTriggered()));
	connect(actionabout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTriggered()));
}

PluginHelp::~PluginHelp()
{
}

QString PluginHelp::getPluginName()
{
	return QString(tr("Help"));
}

QString PluginHelp::getPluginVersion()
{
	return QString(tr("0.0.6"));
}

QString PluginHelp::getPluginDescription()
{
	return QString(tr("PluginHelp provides the help and about dialogues."));
}

QStringList PluginHelp::getPluginDependencies()
{
	return QStringList();
}

void PluginHelp::actionHelpTriggered()
{
	QDialog *dialog = new QDialog(CDevStudioPlatform::getInstance()->getWindow());
	dialog->setMinimumSize(500, 400);
	dialog->setWindowTitle(tr("Help"));
	
	QDialogButtonBox *buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok, Qt::Horizontal, dialog);
	QTextBrowser *textbrowser = new QTextBrowser(dialog);
	textbrowser->setText(CDevStudioPlatform::getInstance()->getBackend()->readFile(":/data/help.html"));
	textbrowser->setOpenExternalLinks(true);
	textbrowser->setReadOnly(true);
	
	QGridLayout *layout = new QGridLayout(dialog);
	layout->addWidget(textbrowser, 0, 0, 1, 1);
	layout->addWidget(buttonbox, 1, 0, 1, 1);
	
	connect(buttonbox, SIGNAL(accepted()), dialog, SLOT(accept()));
	
	dialog->exec();
}

void PluginHelp::actionAboutTriggered()
{
	QDialog *dialog = new QDialog(CDevStudioPlatform::getInstance()->getWindow());
	dialog->setMinimumSize(500, 400);
	dialog->setWindowTitle(tr("About"));
	
	QDialogButtonBox *buttonbox = new QDialogButtonBox(QDialogButtonBox::Ok, Qt::Horizontal, dialog);
	QTabWidget *tabwidget = new QTabWidget(dialog);
	
	QWidget *widgetabout = new QWidget(tabwidget);
	QWidget *widgetlicense = new QWidget(tabwidget);
	QWidget *widgetthanksto = new QWidget(tabwidget);
	
	QTextBrowser *textbrowserabout = new QTextBrowser(widgetabout);
	QTextBrowser *textbrowserlicense = new QTextBrowser(widgetlicense);
	QTextBrowser *textbrowserthanksto = new QTextBrowser(widgetthanksto);
	
	textbrowserabout->setText(CDevStudioPlatform::getInstance()->getBackend()->readFile(":/data/about_about.html"));
	textbrowserlicense->setText(CDevStudioPlatform::getInstance()->getBackend()->readFile(":/data/about_license.html"));
	textbrowserthanksto->setText(CDevStudioPlatform::getInstance()->getBackend()->readFile(":/data/about_thanksto.html"));
	
	textbrowserabout->setOpenExternalLinks(true);
	textbrowserlicense->setOpenExternalLinks(true);
	textbrowserthanksto->setOpenExternalLinks(true);
	
	textbrowserabout->setReadOnly(true);
	textbrowserlicense->setReadOnly(true);
	textbrowserthanksto->setReadOnly(true);
	
	QGridLayout *layoutabout = new QGridLayout(widgetabout);
	QGridLayout *layoutlicense = new QGridLayout(widgetlicense);
	QGridLayout *layoutthanksto = new QGridLayout(widgetthanksto);
	
	layoutabout->addWidget(textbrowserabout);
	layoutlicense->addWidget(textbrowserlicense);
	layoutthanksto->addWidget(textbrowserthanksto);
	
	tabwidget->addTab(widgetabout, tr("About"));
	tabwidget->addTab(widgetlicense, tr("License"));
	tabwidget->addTab(widgetthanksto, tr("Thanks to"));
	
	QGridLayout *layout = new QGridLayout(dialog);
	layout->addWidget(tabwidget, 0, 0, 1, 1);
	layout->addWidget(buttonbox, 1, 0, 1, 1);
	
	connect(buttonbox, SIGNAL(accepted()), dialog, SLOT(accept()));
	
	dialog->exec();
}
