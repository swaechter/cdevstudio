#include "CDevStudioAction.h"

CDevStudioAction::CDevStudioAction(const QString &text, QWidget *parent) : QAction(parent)
{
	setText(text);
}

CDevStudioAction::~CDevStudioAction()
{

}
