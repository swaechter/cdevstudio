#include "WindowManager.h"

WindowManager::WindowManager(Window *window)
{
	m_Window = window;
}

WindowManager::WindowManager()
{
}

Window *WindowManager::getWindow()
{
	return m_Window;
}
