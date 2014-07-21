#include "PluginTextEditor.h"

PluginTextEditor::PluginTextEditor()
{
	Settings *settings = IPlatform::getInstance()->getWindowManager()->getWindow()->getSettingsDialog();
	PluginPage *pluginpage = new PluginPage(settings);
	settings->addSettingsPage(pluginpage);
	
	ProjectManager *projectmanager = IPlatform::getInstance()->getProjectManager();
	connect(projectmanager, SIGNAL(fileOpened(QString)), this , SLOT(openFile(QString)));
	connect(projectmanager, SIGNAL(fileClosed(QString)), this, SLOT(closeFile(QString)));
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
	}
}

void PluginTextEditor::closeFile(QString file)
{
	Project *project = IPlatform::getInstance()->getProjectManager()->getProject();
	if(project)
	{
		QTabWidget *tabwidget = IPlatform::getInstance()->getWindowManager()->getWindow()->getTabWidget();
		
		for(int i = 0; i < tabwidget->count(); i++)
		{
			if(file.compare(tabwidget->tabText(i)) == 0)
			{
				QWidget *widget = tabwidget->widget(i);
				tabwidget->removeTab(i);
				delete widget;
				break;
			}
		}
	}
}
