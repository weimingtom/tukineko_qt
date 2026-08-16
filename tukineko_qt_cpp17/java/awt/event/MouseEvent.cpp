#include "MouseEvent.h"

namespace java {
namespace awt {
namespace event {

MouseEvent::MouseEvent()
    : x(0)
    , y(0)
{
}

int MouseEvent::getX()
{
    return x;
}

int MouseEvent::getY()
{
    return y;
}

Component* MouseEvent::getComponent()
{
    return nullptr;
}

} // namespace event
} // namespace awt
} // namespace java
