#include "component.h"

Component::Component()
    : m_width(0)
    , m_height(0)
    , m_x(0)
    , m_y(0)
    , m_background(new Color_(0, 0, 0))
    , m_foreground(new Color_(255, 255, 255))
{
}

Component::~Component()
{
    if (m_background) delete m_background;
    if (m_foreground) delete m_foreground;
}

int Component::getWidth() const { return m_width; }
int Component::getHeight() const { return m_height; }

void Component::setSize(int w, int h)
{
    m_width = w;
    m_height = h;
}

void Component::setLocation(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Component::setBackground(Color_* color)
{
    if (m_background) delete m_background;
    m_background = color;
}

Color_* Component::getBackground() const { return m_background; }

void Component::setForeground(Color_* color)
{
    if (m_foreground) delete m_foreground;
    m_foreground = color;
}

Color_* Component::getForeground() const { return m_foreground; }
