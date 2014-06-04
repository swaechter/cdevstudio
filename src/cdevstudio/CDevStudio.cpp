#include "CDevStudio.h"

CDevStudio::CDevStudio() : Window()
{
	initPlatform();
	initWindow();
	loadPlugins();
}

CDevStudio::~CDevStudio()
{
	delete m_Platform;
}

void CDevStudio::initPlatform()
{
	m_Platform = new Platform(this);
}

void CDevStudio::initWindow()
{
	setWindowTitle(tr("CDevStudio"));
	resize(1000, 600);
}

void CDevStudio::loadPlugins()
{
	m_Platform->getPluginManager()->loadPlugins();
}
