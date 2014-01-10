#include "CDevStudioBackend.h"

struct CDevStudioBackend::Implementation
{
};

CDevStudioBackend::CDevStudioBackend() : QObject()
{
	implementation = new Implementation();
}

CDevStudioBackend::~CDevStudioBackend()
{
	delete implementation;
}
