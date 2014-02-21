#include "CDevStudioMenuBar.h"

CDevStudioMenuBar::CDevStudioMenuBar(QWidget *parent) : QMenuBar(parent)
{
}

CDevStudioMenuBar::~CDevStudioMenuBar()
{

}

void CDevStudioMenuBar::addMenu(CDevStudioMenu *menu)
{
	QMenu *qmenu = qobject_cast<QMenu *>(menu);
	QMenuBar::addMenu(qmenu);
	listMenues.append(menu);
}

QList<CDevStudioMenu *> CDevStudioMenuBar::getMenues()
{
	return listMenues;
}
