#include "WindowAdapter.h"

namespace java {
namespace awt {
namespace event {

WindowAdapter::WindowAdapter()
{
}

void WindowAdapter::windowClosing(WindowEvent* e)
{
    (void)e;
}

} // namespace event
} // namespace awt
} // namespace java
