#include "CDevStudioPlatform.h"


CDevStudioPlatform::CDevStudioPlatform(CDevStudioWindow *window) : QObject()
{
	cdevstudioWindow = window;
	cdevstudioBackend = new CDevStudioBackend();
	cdevstudioProject = nullptr;
	cdevstudioPlugins = cdevstudioBackend->loadPlugins();
	cdevstudioPlatformPlugins = new CDevStudioPlatformPlugin(cdevstudioWindow, cdevstudioPlugins, cdevstudioBackend);
	
	connect(cdevstudioPlatformPlugins, SIGNAL(addPlatformProjectTemplate(CDevStudioProjectTemplate)), this, SLOT(addProjectTemplate(CDevStudioProjectTemplate)));
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	qDeleteAll<>(cdevstudioPlugins);
	delete cdevstudioPlatformPlugins;
	delete cdevstudioBackend;
	delete cdevstudioProject;
}

void CDevStudioPlatform::initPlugins()
{
	foreach(ICDevStudioPlugin *plugin, cdevstudioPlugins)
	{
		plugin->init(cdevstudioPlatformPlugins);
	}
}

CDevStudioWindow *CDevStudioPlatform::getWindow()
{
	return cdevstudioWindow;
}

QList<CDevStudioProjectTemplate> CDevStudioPlatform::getProjectTemplates()
{
	return cdevstudioProjectTemplates;
}

QList<ICDevStudioPlugin *> CDevStudioPlatform::getPlugins()
{
	return cdevstudioPlugins;
}

CDevStudioProject *CDevStudioPlatform::createProject(QString projectdirectory, QString projectname, QString projecttemplatestring)
{
	if(cdevstudioProject == nullptr)
	{
		projectdirectory = projectdirectory.append(QString("/") + projectname + QString("/"));
		cdevstudioBackend->createDirectory(projectdirectory);
		cdevstudioBackend->createFile(projectdirectory + QString("Project.cdev"));
		cdevstudioBackend->writeFile(projectdirectory + QString("Project.cdev"), projectname);
		
		cdevstudioProject = new CDevStudioProject(projectname, projectdirectory);
		
		foreach(CDevStudioProjectTemplate projecttemplate, cdevstudioProjectTemplates)
		{
			if(projecttemplatestring.compare(projecttemplate.getTemplateName()) == 0)
			{
				foreach(QString file, projecttemplate.getTemplateFiles())
				{
					QString filepath = projectdirectory + cdevstudioBackend->getNameOfFile(file);
					cdevstudioBackend->createFile(filepath);
					cdevstudioBackend->writeFile(filepath, cdevstudioBackend->readFile(file));
				}
				break;
			}
		}
		
		return cdevstudioProject;
	}
	else
	{
		return nullptr;
	}
}

CDevStudioProject *CDevStudioPlatform::loadProject(QString projectfile)
{
	if(!projectfile.isEmpty())
	{
		QString projectdirectory = cdevstudioBackend->getDirectoryOfFile(projectfile) + QString("/");
		QString projectname = cdevstudioBackend->readFile(projectfile);
		cdevstudioProject = new CDevStudioProject(projectname, projectdirectory);
		return cdevstudioProject;
	}
	else
	{
		return nullptr;
	}
}

CDevStudioProject *CDevStudioPlatform::getProject()
{
	return cdevstudioProject;
}

void CDevStudioPlatform::closeProject()
{
	if(cdevstudioProject != nullptr)
	{
		delete cdevstudioProject;
		cdevstudioProject = nullptr;
	}
}

void CDevStudioPlatform::addProjectTemplate(CDevStudioProjectTemplate projecttemplate)
{
	cdevstudioProjectTemplates.append(projecttemplate);
}
