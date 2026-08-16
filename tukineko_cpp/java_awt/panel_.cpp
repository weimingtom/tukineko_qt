#include "panel_.h"

Panel_::Panel_()
    : m_cursor(0)
{
}

Panel_::~Panel_()
{
}

void Panel_::addMouseListener(MouseListener* listener)
{
    if (listener && !m_mouseListeners.contains(listener)) {
        m_mouseListeners.append(listener);
    }
}

void Panel_::removeMouseListener(MouseListener* listener)
{
    m_mouseListeners.removeOne(listener);
}

void Panel_::setCursor(int cursorType)
{
    m_cursor = cursorType;
}

void Panel_::setLayout(void* layout)
{
    // Layout management - placeholder
}

void Panel_::paint(Graphics_* g)
{
    // Default painting - subclasses should override
}
