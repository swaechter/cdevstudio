#include "CDevStudioSystemPlatform.h"

struct CDevStudioSystemPlatform::Implementation
{
	CDevStudioBackend *backend;
};

CDevStudioSystemPlatform::CDevStudioSystemPlatform() : QObject()
{
	implementation = new Implementation();
	implementation->backend = new CDevStudioBackend();
}

CDevStudioSystemPlatform::~CDevStudioSystemPlatform()
{
	delete implementation->backend;
	delete implementation;
}
