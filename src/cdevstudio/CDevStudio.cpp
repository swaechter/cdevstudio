#include "CDevStudio.h"

CDevStudio::CDevStudio() : QMainWindow()
{
	initPlatform();
}

CDevStudio::~CDevStudio()
{
	delete m_Platform;
}

void CDevStudio::initPlatform()
{
	m_Platform = new Platform(this);
}
