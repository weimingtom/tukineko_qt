#ifndef MOUSE_LISTENER_H
#define MOUSE_LISTENER_H

#include "mouse_event.h"

class MouseListener
{
public:
    virtual ~MouseListener() {}
    virtual void mousePressed(const MouseEvent& e) = 0;
    virtual void mouseReleased(const MouseEvent& e) {}
    virtual void mouseClicked(const MouseEvent& e) {}
    virtual void mouseEntered(const MouseEvent& e) {}
    virtual void mouseExited(const MouseEvent& e) {}
};

#endif // MOUSE_LISTENER_H
