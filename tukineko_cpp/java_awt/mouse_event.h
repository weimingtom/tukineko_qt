#ifndef MOUSE_EVENT_H
#define MOUSE_EVENT_H

struct MouseEvent
{
    int x;
    int y;
    int clickCount;
    int button;
    
    MouseEvent() : x(0), y(0), clickCount(0), button(0) {}
    MouseEvent(int x_, int y_) : x(x_), y(y_), clickCount(0), button(0) {}
};

#endif // MOUSE_EVENT_H
