#include "Frame.h"

namespace java {
namespace awt {

Frame::Frame()
{
}

void Frame::add(Panel_* p)
{
    Q_UNUSED(p)
}

void Frame::addWindowListener(event::WindowAdapter* wa)
{
    Q_UNUSED(wa)
}

void Frame::pack()
{
}

void Frame::setResizable(bool r)
{
    Q_UNUSED(r)
}

void Frame::setLocationRelativeTo(QObject* o)
{
    Q_UNUSED(o)
}

void Frame::setVisible(bool v)
{
    Q_UNUSED(v)
}

} // namespace awt
} // namespace java
