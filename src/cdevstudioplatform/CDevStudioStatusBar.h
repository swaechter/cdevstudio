#ifndef CDEVSTUDIOSTATUSBAR_H
#define CDEVSTUDIOSTATUSBAR_H

#include <QtWidgets/QStatusBar>

class CDevStudioStatusBar : public QStatusBar
{
	Q_OBJECT
	
public:
	CDevStudioStatusBar(QWidget *parent);
	~CDevStudioStatusBar();
};

#endif // CDEVSTUDIOSTATUSBAR_H
