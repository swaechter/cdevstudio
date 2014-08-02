#include "PluginProject.h"

PluginProject::PluginProject()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindowManager()->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
	
	m_ActionCreateProject = new QAction(tr("Create Project"), window->menuBar());
	m_ActionLoadProject = new QAction(tr("Load Project"), window->menuBar());
	m_ActionCloseProject = new QAction(tr("Close Project"), window->menuBar());
	m_ActionCreateFile = new QAction(tr("Create File"), window->menuBar());
	m_ActionDeleteFile = new QAction(tr("Delete File"), window->menuBar());
	m_ActionRenameFile = new QAction(tr("Rename File"), window->menuBar());
	m_ActionSaveFile = new QAction(tr("Save File"), window->menuBar());
	m_ActionCloseFile = new QAction(tr("Close File"), window->menuBar());
	
	m_ActionCreateProject->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_N);
	m_ActionLoadProject->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_O);
	m_ActionCloseProject->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_Q);
	m_ActionCreateFile->setShortcut(Qt::CTRL | Qt::Key_N);
	m_ActionDeleteFile->setShortcut(Qt::CTRL | Qt::Key_D);
	m_ActionRenameFile->setShortcut(Qt::CTRL | Qt::Key_R);
	m_ActionSaveFile->setShortcut(Qt::CTRL | Qt::Key_S);
	m_ActionCloseFile->setShortcut(Qt::CTRL | Qt::Key_Q);
	
	window->getMenu(MenuProject)->addAction(m_ActionCreateProject);
	window->getMenu(MenuProject)->addAction(m_ActionLoadProject);
	window->getMenu(MenuProject)->addAction(m_ActionCloseProject);
	window->getMenu(MenuFile)->addAction(m_ActionCreateFile);
	window->getMenu(MenuFile)->addAction(m_ActionDeleteFile);
	window->getMenu(MenuFile)->addAction(m_ActionRenameFile);
	window->getMenu(MenuFile)->addSeparator();
	window->getMenu(MenuFile)->addAction(m_ActionSaveFile);
	window->getMenu(MenuFile)->addSeparator();
	window->getMenu(MenuFile)->addAction(m_ActionCloseFile);
	
	connect(m_ActionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionCreateProjectTrigger()));
	connect(m_ActionLoadProject, SIGNAL(triggered(bool)), this, SLOT(actionLoadProjectTrigger()));
	connect(m_ActionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProjectTrigger()));
	connect(m_ActionCreateFile, SIGNAL(triggered(bool)), this, SLOT(actionCreateFileTrigger()));
	connect(m_ActionDeleteFile, SIGNAL(triggered(bool)), this, SLOT(actionDeleteFileTrigger()));
	connect(m_ActionRenameFile, SIGNAL(triggered(bool)), this, SLOT(actionRenameFileTrigger()));
	connect(m_ActionSaveFile, SIGNAL(triggered(bool)), this, SLOT(actionSaveFileTrigger()));
	connect(m_ActionCloseFile, SIGNAL(triggered(bool)), this, SLOT(actionCloseFileTrigger()));
}

PluginProject::~PluginProject()
{
}

void PluginProject::actionCreateProjectTrigger()
{
	if(!m_Platform->getProjectManager()->getProject())
	{
		QList<ProjectTemplate> templates;
		templates.append(ProjectTemplate(tr("Empty Project"), tr("An empty project"), QStringList()));
		templates.append(ProjectTemplate(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c"));
		templates.append(ProjectTemplate(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp"));
		
		CreateProjectDialog *dialog = new CreateProjectDialog(templates, m_Platform->getWindowManager()->getWindow());
		if(dialog->exec() == QDialog::Accepted)
		{
			if(!dialog->getProjectName().isEmpty() && !dialog->getProjectName().isEmpty() && !dialog->getProjectLocation().isEmpty())
			{
				foreach(ProjectTemplate projecttemplate, templates)
				{
					if(projecttemplate.getName().compare(dialog->getTemplateName()) == 0)
					{
						if(!m_Platform->getProjectManager()->createProject(dialog->getProjectName(), dialog->getProjectLocation(), projecttemplate.getFiles()))
						{
							QMessageBox::critical(m_Platform->getWindowManager()->getWindow(), tr("Error"), tr("The system was unable to create the project."));
						}
						break;
					}
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("Please close the current project before you create a new one."));
	}
}

void PluginProject::actionLoadProjectTrigger()
{
	if(!m_Platform->getProjectManager()->getProject())
	{
		QString projectfile = QFileDialog::getOpenFileName(m_Platform->getWindowManager()->getWindow(), tr("Load project"), QDir::homePath(), tr("Project (*.cdev)"));
		if(!projectfile.isEmpty())
		{
			if(!m_Platform->getProjectManager()->loadProject(projectfile))
			{
				QMessageBox::critical(m_Platform->getWindowManager()->getWindow(), tr("Error"), tr("The system was unable to load the project."));
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("Please close the current project before you open a new one."));
	}
}

void PluginProject::actionCloseProjectTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		m_Platform->getProjectManager()->closeProject();
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("There is no active project to close."));
	}
}

void PluginProject::actionCreateFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		QString filepath = QFileDialog::getSaveFileName(m_Platform->getWindowManager()->getWindow(), tr("Create a new file"), m_Platform->getProjectManager()->getProject()->getLocation());
		if(!filepath.isEmpty() && m_Platform->getProjectManager()->isFilepathInProject(filepath))
		{
			QString file = filepath.remove(m_Platform->getProjectManager()->getProject()->getLocation());
			if(!m_Platform->getProjectManager()->createFile(file))
			{
				QMessageBox::critical(m_Platform->getWindowManager()->getWindow(), tr("Error"), tr("The system was unable to create the file."));
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("Please create or load a project."));
	}
}

void PluginProject::actionDeleteFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindowManager()->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			QString file = m_Platform->getWindowManager()->getWindow()->getTabWidget()->tabText(index);
			if(QMessageBox::question(m_Platform->getWindowManager()->getWindow(), tr("Delete"), tr("Do you want to delete the current file?")) == QMessageBox::Yes)
			{
				if(!m_Platform->getProjectManager()->deleteFile(file))
				{
						QMessageBox::critical(m_Platform->getWindowManager()->getWindow(), tr("Error"), tr("The system was unable to delete the current file."));
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("Please create or load a project."));
	}
}

void PluginProject::actionRenameFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindowManager()->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			bool result = false;
			QString file = m_Platform->getWindowManager()->getWindow()->getTabWidget()->tabText(index);
			QString filepath = m_Platform->getProjectManager()->getProject()->getLocation() + file;
			QStringList fileparts = filepath.split("/");
			QString text = fileparts.at(fileparts.count() - 1);
			QString newtext = QInputDialog::getText(m_Platform->getWindowManager()->getWindow(), tr("Rename"), tr("New file name"), QLineEdit::Normal, text, &result);
			if(result && !newtext.isEmpty())
			{
				fileparts.removeLast();
				fileparts.append(newtext);
				QString newfilepath = fileparts.join("/");
				QString newfile = newfilepath.remove(m_Platform->getProjectManager()->getProject()->getLocation());
				if(!m_Platform->getProjectManager()->renameFile(file, newfile))
				{
					QMessageBox::critical(m_Platform->getWindowManager()->getWindow(), tr("Error"), tr("The system was unable to rename the current file."));
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("Please create or load a project."));
	}
}

void PluginProject::actionSaveFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindowManager()->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			QString file = m_Platform->getWindowManager()->getWindow()->getTabWidget()->tabText(index);
			QTextEdit *textedit = m_Platform->getWindowManager()->getWindow()->getTabWidget()->getTextEdit(file);
			if(textedit)
			{
				QString text = textedit->toPlainText();
				if(!m_Platform->getProjectManager()->writeFile(file, text))
				{
					QMessageBox::critical(m_Platform->getWindowManager()->getWindow(), tr("Error"), tr("The system was unable to write the current file."));
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("Please create or load a project."));
	}
}

void PluginProject::actionCloseFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindowManager()->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			QString file = m_Platform->getWindowManager()->getWindow()->getTabWidget()->tabText(index);
			if(!m_Platform->getProjectManager()->closeFile(file))
			{
				QMessageBox::critical(m_Platform->getWindowManager()->getWindow(), tr("Error"), tr("The system was unable to close the current file."));
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindowManager()->getWindow(), tr("Information"), tr("Please create or load a project."));
	}
}
