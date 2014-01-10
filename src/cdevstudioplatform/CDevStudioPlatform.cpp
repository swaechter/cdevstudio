#include "CDevStudioPlatform.h"

struct CDevStudioPlatform::Implementation
{
	CDevStudioBackend *backend;
};

CDevStudioPlatform::CDevStudioPlatform() : QObject()
{
	implementation = new Implementation();
	implementation->backend = new CDevStudioBackend();
}

CDevStudioPlatform::~CDevStudioPlatform()
{
	delete implementation->backend;
	delete implementation;
}
