#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <cdevstudioplatform/Platform.h>
#include <cdevstudioplatform/Window.h>

class CDevStudio : public Window
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	void initPlatform();
	void initWindow();
	void loadPlugins();
	
	Platform *m_Platform;
};

#endif // CDEVSTUDIO_H
