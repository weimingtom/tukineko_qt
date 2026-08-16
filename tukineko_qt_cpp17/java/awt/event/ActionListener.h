#ifndef JAVA_AWT_EVENT_ACTIONLISTENER_H
#define JAVA_AWT_EVENT_ACTIONLISTENER_H

#include "ActionEvent.h"

namespace java {
namespace awt {
namespace event {

class ActionListener {
public:
    virtual ~ActionListener() {}
    virtual void actionPerformed(ActionEvent* event_) = 0;
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_ACTIONLISTENER_H
