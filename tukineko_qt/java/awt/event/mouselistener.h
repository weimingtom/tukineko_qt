#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include "mouseevent.h"

class MouseListener
{
public:
    virtual ~MouseListener() {}

    virtual void mouseClicked(MouseEvent* event) = 0;
    virtual void mouseEntered(MouseEvent* event) = 0;
    virtual void mouseExited(MouseEvent* event) = 0;
    virtual void mouseReleased(MouseEvent* event) = 0;
    virtual void mousePressed(MouseEvent* event) = 0;
};

#endif // MOUSELISTENER_H
