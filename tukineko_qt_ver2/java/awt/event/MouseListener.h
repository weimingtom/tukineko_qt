#ifndef JAVA_AWT_EVENT_MOUSELISTENER_H
#define JAVA_AWT_EVENT_MOUSELISTENER_H

#include "MouseEvent.h"

namespace java {
namespace awt {
namespace event {

class MouseListener {
public:
    virtual ~MouseListener() {}
    virtual void mouseClicked(MouseEvent* event_) = 0;
    virtual void mouseEntered(MouseEvent* event_) = 0;
    virtual void mouseExited(MouseEvent* event_) = 0;
    virtual void mouseReleased(MouseEvent* event_) = 0;
    virtual void mousePressed(MouseEvent* event_) = 0;
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_MOUSELISTENER_H
