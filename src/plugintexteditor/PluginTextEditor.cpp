#include "PluginTextEditor.h"

PluginTextEditor::PluginTextEditor()
{
	ProjectManager *projectmanager = IPlatform::getInstance()->getProjectManager();
	
	Window *window = IPlatform::getInstance()->getWindowManager()->getWindow();
	QTabWidget *tabwidget = window->getTabWidget();
	QTextEdit *textedit = new QTextEdit(tr("Welcome!"), tabwidget);
	tabwidget->addTab(textedit, tr("Welcome"));
	
	Settings *settings = window->getSettingsDialog();
	PluginPage *pluginpage = new PluginPage(settings);
	settings->addSettingsPage(pluginpage);
	
	connect(projectmanager, SIGNAL(fileOpened(QString)), this, SLOT(openFile(QString)));
	connect(projectmanager, SIGNAL(fileClosed(QString)), this, SLOT(closeFile(QString)));
	connect(window, SIGNAL(closeTabRequested(QString)), this, SLOT(closeFileRequest(QString)));
}

PluginTextEditor::~PluginTextEditor()
{
}

void PluginTextEditor::openFile(QString file)
{
	Project *project = IPlatform::getInstance()->getProjectManager()->getProject();
	if(project)
	{
		QTabWidget *tabwidget = IPlatform::getInstance()->getWindowManager()->getWindow()->getTabWidget();
		QTextEdit *textedit = new QTextEdit(tabwidget);
		textedit->setText(Backend::readFile(project->getLocation() + file));
		tabwidget->addTab(textedit, file);
		tabwidget->setCurrentWidget(textedit);
	}
}

void PluginTextEditor::closeFile(QString file)
{
	QTabWidget *tabwidget = IPlatform::getInstance()->getWindowManager()->getWindow()->getTabWidget();
	for(int i = 0; i < tabwidget->count(); i++)
	{
		if(file.compare(tabwidget->tabText(i)) == 0)
		{
			QWidget *widget = tabwidget->widget(i);
			tabwidget->removeTab(i);
			delete widget;
		}
	}
}

void PluginTextEditor::closeFileRequest(QString file)
{
	QTabWidget *tabwidget = IPlatform::getInstance()->getWindowManager()->getWindow()->getTabWidget();
	for(int i = 0; i < tabwidget->count(); i++)
	{
		if(file.compare(tabwidget->tabText(i)) == 0)
		{
			if(tabwidget->tabText(i).compare(QString(tr("Welcome"))) == 0)
			{
				QWidget *widget = tabwidget->widget(i);
				tabwidget->removeTab(i);
				delete widget;
			}
			else
			{
				ProjectManager * projectmanager = IPlatform::getInstance()->getProjectManager();
				if(projectmanager->getProject())
				{
					projectmanager->closeFile(file);
				}
			}
			break;
		}
	}
}
