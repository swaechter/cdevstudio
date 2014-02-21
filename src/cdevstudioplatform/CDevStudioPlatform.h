#ifndef CDEVSTUDIOPLATFORM_H
#define CDEVSTUDIOPLATFORM_H

#include "CDevStudioPlatformExport.h"
#include "CDevStudioWindow.h"
#include "CDevStudioProject.h"
#include "CDevStudioBackend.h"

class CDEVSTUDIOPLATFORM_API CDevStudioPlatform
{
private:
	CDevStudioPlatform(); // Singleton
	
public:
	~CDevStudioPlatform();
	
	static CDevStudioPlatform *getInstance();
	void setWindow(CDevStudioWindow *window);
	CDevStudioWindow *getWindow();
	CDevStudioBackend *getBackend();
	
private:
	// Singleton
	static CDevStudioPlatform *instance;
	
	// Private implementation
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOPLATFORM_H
