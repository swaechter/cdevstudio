#include "CDevStudioPlatform.h"

struct CDevStudioPlatform::Implementation
{
	CDevStudioBackend *backend;
	QList<CDevStudioProject *> projects;
};

CDevStudioPlatform::CDevStudioPlatform() : QObject()
{
	implementation = new Implementation();
	implementation->backend = new CDevStudioBackend();
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	delete implementation->backend;
	qDeleteAll<>(implementation->projects);
	delete implementation;
}

CDevStudioProject *CDevStudioPlatform::createProject(const QString &projectname, const QString &projectdirectory)
{
	CDevStudioProject *project = new CDevStudioProject(projectname, projectdirectory + QString("/") + projectname);
	implementation->projects.append(project);
	implementation->backend->createDirectory(project->getProjectDirectory());
	implementation->backend->writeFile(project->getProjectFile(), projectname);
	return project;
}

CDevStudioProject *CDevStudioPlatform::loadProject(const QString &projectfile)
{
	QString projectname = implementation->backend->readFile(projectfile);
	if(projectname.length())
	{
		CDevStudioProject *project = new CDevStudioProject(projectname, implementation->backend->getDirectoryOfFile(projectfile));
		implementation->projects.append(project);
		return project;
	}
	else
	{
		return nullptr;
	}
}

bool CDevStudioPlatform::closeProject(CDevStudioProject *project)
{
	if(implementation->projects.contains(project))
	{
		implementation->projects.removeOne(project);
		delete project;
		return true;
	}
	else
	{
		return false;
	}
}

bool CDevStudioPlatform::buildProject(CDevStudioProject *project)
{
	return false;
}

bool CDevStudioPlatform::runProject(CDevStudioProject *project)
{
	return false;
}

QList<CDevStudioProject *> CDevStudioPlatform::getProjects()
{
	return implementation->projects;
}
