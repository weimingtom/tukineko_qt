#include "WindowAdapter.h"

namespace java {
namespace awt {
namespace event {

WindowAdapter::WindowAdapter()
{
}

void WindowAdapter::windowClosing(WindowEvent* e)
{
    Q_UNUSED(e)
}

} // namespace event
} // namespace awt
} // namespace java
