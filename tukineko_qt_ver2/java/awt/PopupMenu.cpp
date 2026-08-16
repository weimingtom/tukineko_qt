#include "PopupMenu.h"

namespace java {
namespace awt {

PopupMenu::PopupMenu()
    : Menu()
{
}

void PopupMenu::add(Menu* menu)
{
    Q_UNUSED(menu)
}

void PopupMenu::addSeparator()
{
}

void PopupMenu::show(Component* c, int x, int y)
{
    Q_UNUSED(c)
    Q_UNUSED(x)
    Q_UNUSED(y)
}

} // namespace awt
} // namespace java
