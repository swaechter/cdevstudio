#ifndef CDEVSTUDIOMENU_H
#define CDEVSTUDIOMENU_H

#include <QtWidgets/QMenu>

class CDevStudioMenu : public QMenu
{
	Q_OBJECT
	
public:
	CDevStudioMenu(const QString &title, QWidget *parent);
	~CDevStudioMenu();
};

#endif // CDEVSTUDIOMENU_H
