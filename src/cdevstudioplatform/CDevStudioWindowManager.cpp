#include "CDevStudioWindowManager.h"

CDevStudioWindowManager::CDevStudioWindowManager(CDevStudioWindow *window)
{
	m_Window = window;
}

CDevStudioWindowManager::CDevStudioWindowManager()
{

}

CDevStudioWindow *CDevStudioWindowManager::getWindow()
{
	return m_Window;
}
