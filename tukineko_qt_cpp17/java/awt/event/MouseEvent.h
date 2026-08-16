#ifndef JAVA_AWT_EVENT_MOUSEEVENT_H
#define JAVA_AWT_EVENT_MOUSEEVENT_H

#include "../Component.h"

namespace java {
namespace awt {
namespace event {

class MouseEvent {
public:
    int x;
    int y;

    MouseEvent();

    int getX();
    int getY();
    Component* getComponent();
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_MOUSEEVENT_H
