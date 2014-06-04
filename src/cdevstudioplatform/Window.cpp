#include "Window.h"

Window::Window() : QMainWindow()
{
	QTabWidget *tabwidget = new QTabWidget(this);
	setCentralWidget(tabwidget);
	
	QTextEdit *textedit = new QTextEdit(tabwidget);
	tabwidget->addTab(textedit, "Welcome");
}

Window::~Window()
{
}
