#include "WindowManager.h"

WindowManager::WindowManager(Window *window, QObject *parent) : QObject(parent)
{
	m_Window = window;
}

Window *WindowManager::getWindow()
{
	return m_Window;
}
