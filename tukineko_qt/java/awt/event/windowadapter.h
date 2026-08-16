#ifndef WINDOWADAPTER_H
#define WINDOWADAPTER_H

#include <QObject>
#include "windowevent.h"

class WindowAdapter //: public QObject
{
//    Q_OBJECT

public:
    WindowAdapter(/*QObject* parent = nullptr*/);
    virtual ~WindowAdapter();

    virtual void windowClosing(WindowEvent* e);

//signals:
//    void windowClosing(WindowEvent* e);
};

#endif // WINDOWADAPTER_H
