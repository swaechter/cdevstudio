#include "Window.h"

Window::Window() : QMainWindow()
{
	QStackedWidget *stackedwidget = new QStackedWidget(this);
	QTextEdit *textedit = new QTextEdit(stackedwidget);
	stackedwidget->addWidget(textedit);
	
	setCentralWidget(stackedwidget);
	setMinimumSize(800, 500);
	setWindowTitle(tr("CDevStudio"));
}

Window::~Window()
{
}
