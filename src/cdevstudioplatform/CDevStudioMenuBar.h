#ifndef CDEVSTUDIOMENUBAR_H
#define CDEVSTUDIOMENUBAR_H

#include <QtWidgets/QMenuBar>
#include <QtCore/QList>

#include "CDevStudioMenu.h"

class CDevStudioMenuBar : public QMenuBar
{
	Q_OBJECT
	
public:
	CDevStudioMenuBar(QWidget *parent);
	~CDevStudioMenuBar();
	void addMenu(CDevStudioMenu *menu);
	QList<CDevStudioMenu *> getMenues();
	
private:
	QList<CDevStudioMenu *> listMenues;
};

#endif // CDEVSTUDIOMENUBAR_H
