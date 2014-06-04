#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>

#include "PlatformExport.h"

class CDEVSTUDIOPLATFORM_EXPORT Window : public QMainWindow
{
    Q_OBJECT
    
public:
    Window();
    virtual ~Window();
};

#endif // WINDOW_H
