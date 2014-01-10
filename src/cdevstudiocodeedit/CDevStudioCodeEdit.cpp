#include "CDevStudioCodeEdit.h"

struct CDevStudioCodeEdit::Implementation
{
};

CDevStudioCodeEdit::CDevStudioCodeEdit(QWidget *parent) : QTextEdit(parent)
{
	implementation = new Implementation();
}

CDevStudioCodeEdit::~CDevStudioCodeEdit()
{
	delete implementation;
}
