#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "component.h"

class MouseEvent
{
public:
    int x;
    int y;

    MouseEvent();
    virtual ~MouseEvent();

    int getX() const { return x; }
    int getY() const { return y; }
    Component* getComponent() const { return nullptr; }
};

#endif // MOUSEEVENT_H
