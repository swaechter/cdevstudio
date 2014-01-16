#include "CDevStudioProjectPlatform.h"

struct CDevStudioProjectPlatform::Implementation
{
	CDevStudioBackend *backend;
	QList<CDevStudioProject *> projects;
};

CDevStudioProjectPlatform::CDevStudioProjectPlatform() : QObject()
{
	implementation = new Implementation();
	implementation->backend = new CDevStudioBackend();
}

CDevStudioProjectPlatform::~CDevStudioProjectPlatform()
{
	delete implementation->backend;
	qDeleteAll<>(implementation->projects);
	delete implementation;
}

CDevStudioProject *CDevStudioProjectPlatform::createProject(const QString &projectname, const QString &projectdirectory)
{
	CDevStudioProject *project = new CDevStudioProject(projectname, projectdirectory + QString("/") + projectname);
	implementation->projects.append(project);
	implementation->backend->createDirectory(project->getProjectDirectory());
	implementation->backend->writeFile(project->getProjectFile(), projectname);
	return project;
}

CDevStudioProject *CDevStudioProjectPlatform::loadProject(const QString &projectfile)
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

bool CDevStudioProjectPlatform::closeProject(CDevStudioProject *project)
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

bool CDevStudioProjectPlatform::buildProject(CDevStudioProject *project)
{
	return false;
}

bool CDevStudioProjectPlatform::runProject(CDevStudioProject *project)
{
	return false;
}

QList<CDevStudioProject *> CDevStudioProjectPlatform::getProjects()
{
	return implementation->projects;
}
