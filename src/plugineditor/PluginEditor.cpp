#include "PluginEditor.h"

PluginEditor::PluginEditor()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindowManager()->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
	
	QTabWidget *tabwidget = window->getTabWidget();
	QTextEdit *textedit = new QTextEdit(tr("Welcome!"), tabwidget);
	textedit->setReadOnly(true);
	tabwidget->addTab(textedit, tr("Welcome"));
	
	connect(m_Platform->getProjectManager(), SIGNAL(fileOpened(QString)), this, SLOT(openFile(QString)));
	connect(m_Platform->getProjectManager(), SIGNAL(fileClosed(QString)), this, SLOT(closeFile(QString)));
	connect(window, SIGNAL(closeTabRequested(QString)), this, SLOT(closeFileRequest(QString)));
}

PluginEditor::~PluginEditor()
{
}

void PluginEditor::openFile(QString file)
{
	Project *project = m_Platform->getProjectManager()->getProject();
	if(project)
	{
		QTabWidget *tabwidget = m_Platform->getWindowManager()->getWindow()->getTabWidget();
		QTextEdit *textedit = new QTextEdit(tabwidget);
		textedit->setText(Backend::readFile(project->getLocation() + file));
		tabwidget->addTab(textedit, file);
		tabwidget->setCurrentWidget(textedit);
	}
}

void PluginEditor::closeFile(QString file)
{
	QTabWidget *tabwidget = m_Platform->getWindowManager()->getWindow()->getTabWidget();
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

void PluginEditor::closeFileRequest(QString file)
{
	QTabWidget *tabwidget = m_Platform->getWindowManager()->getWindow()->getTabWidget();
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
				ProjectManager * projectmanager = m_Platform->getProjectManager();
				if(projectmanager->getProject())
				{
					projectmanager->closeFile(file);
				}
			}
			break;
		}
	}
}
