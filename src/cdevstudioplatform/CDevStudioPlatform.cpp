#include "CDevStudioPlatform.h"

CDevStudioPlatform *CDevStudioPlatform::instance = nullptr;

struct CDevStudioPlatform::Implementation
{
	CDevStudioWindow *window;
	CDevStudioBackend *backend;
};

CDevStudioPlatform::CDevStudioPlatform()
{
	implementation = new Implementation();
	implementation->backend = new CDevStudioBackend();
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	delete implementation->backend;
	delete implementation;
}

CDevStudioPlatform *CDevStudioPlatform::getInstance()
{
	if(instance == nullptr)
	{
		instance = new CDevStudioPlatform();
	}
	return instance;
}

void CDevStudioPlatform::setWindow(CDevStudioWindow *window)
{
	implementation->window = window;
}

CDevStudioWindow *CDevStudioPlatform::getWindow()
{
	return implementation->window;
}

CDevStudioBackend *CDevStudioPlatform::getBackend()
{
	return implementation->backend;
}
