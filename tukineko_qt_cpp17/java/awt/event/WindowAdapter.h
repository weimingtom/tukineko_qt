#ifndef JAVA_AWT_EVENT_WINDOWADAPTER_H
#define JAVA_AWT_EVENT_WINDOWADAPTER_H

#include "WindowEvent.h"

namespace java {
namespace awt {
namespace event {

class WindowAdapter {
public:
    WindowAdapter();

    virtual void windowClosing(WindowEvent* e);
};

} // namespace event
} // namespace awt
} // namespace java

#endif // JAVA_AWT_EVENT_WINDOWADAPTER_H
