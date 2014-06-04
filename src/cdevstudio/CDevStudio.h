#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <QtWidgets/QMainWindow>

#include <cdevstudioplatform/Platform.h>

class CDevStudio : public QMainWindow
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	void initPlatform();
	
	Platform *m_Platform;
};

#endif // CDEVSTUDIO_H
