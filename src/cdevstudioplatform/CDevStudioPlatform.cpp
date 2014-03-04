#include "CDevStudioPlatform.h"


CDevStudioPlatform::CDevStudioPlatform(CDevStudioWindow *window) : QObject()
{
	cdevstudioWindow = window;
	cdevstudioData.setPlugins(cdevstudioBackend.loadPlugins());
	cdevstudioData.clearProject();
	cdevstudioPlatformPlugins = new CDevStudioPlatformPlugin(cdevstudioWindow, &cdevstudioBackend, &cdevstudioData);
	connect(cdevstudioPlatformPlugins, SIGNAL(addPlatformProjectTemplate(CDevStudioProjectTemplate)), this, SLOT(addProjectTemplate(CDevStudioProjectTemplate)));
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	cdevstudioData.clearProject();
	delete cdevstudioPlatformPlugins;
}

void CDevStudioPlatform::initPlugins()
{
	foreach(ICDevStudioPlugin *plugin, cdevstudioData.getPlugins())
	{
		plugin->init(cdevstudioPlatformPlugins);
	}
}

CDevStudioWindow *CDevStudioPlatform::getWindow()
{
	return cdevstudioWindow;
}

CDevStudioBackend *CDevStudioPlatform::getBackend()
{
	return &cdevstudioBackend;
}

CDevStudioData *CDevStudioPlatform::getData()
{
	return &cdevstudioData;
}

CDevStudioProject *CDevStudioPlatform::createProject(QString projectdirectory, QString projectname, QString projecttemplatestring)
{
	if(cdevstudioData.getProject() == nullptr)
	{
		QString realprojectdirectory = realprojectdirectory.append(QString("/") + projectname + QString("/"));
		cdevstudioBackend.createDirectory(realprojectdirectory);
		cdevstudioBackend.createFile(realprojectdirectory + QString("Project.cdev"));
		cdevstudioBackend.writeFile(realprojectdirectory + QString("Project.cdev"), projectname);
		
		CDevStudioProject *project = new CDevStudioProject(projectname, realprojectdirectory);
		cdevstudioData.clearProject();
		cdevstudioData.setProject(project);
		
		foreach(CDevStudioProjectTemplate projecttemplate, cdevstudioData.getProjectTemplates())
		{
			if(projecttemplatestring.compare(projecttemplate.getTemplateName()) == 0)
			{
				foreach(QString file, projecttemplate.getTemplateFiles())
				{
					QString filepath = realprojectdirectory + cdevstudioBackend.getNameOfFile(file);
					cdevstudioBackend.createFile(filepath);
					cdevstudioBackend.writeFile(filepath, cdevstudioBackend.readFile(file));
				}
				break;
			}
		}
		
		return cdevstudioData.getProject();
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
		QString projectdirectory = cdevstudioBackend.getDirectoryOfFile(projectfile) + QString("/");
		QString projectname = cdevstudioBackend.readFile(projectfile);
		
		CDevStudioProject *project = new CDevStudioProject(projectname, projectdirectory);
		cdevstudioData.clearProject();
		cdevstudioData.setProject(project);
		
		return cdevstudioData.getProject();
	}
	else
	{
		return nullptr;
	}
}

void CDevStudioPlatform::closeProject()
{
	cdevstudioData.clearProject();
}

void CDevStudioPlatform::addProjectTemplate(CDevStudioProjectTemplate projecttemplate)
{
	cdevstudioData.addProjectTemplate(projecttemplate);
}
