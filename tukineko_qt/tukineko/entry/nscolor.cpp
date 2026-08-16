#include "nscolor.h"

NsColor::NsColor()
    : m_r(0), m_g(0), m_b(0), m_a(255)
{
}

NsColor::NsColor(int r, int g, int b, int a)
    : m_r(r), m_g(g), m_b(b), m_a(a)
{
}

NsColor::NsColor(unsigned int rgba)
    : m_r((rgba >> 16) & 0xFF)
    , m_g((rgba >> 8) & 0xFF)
    , m_b(rgba & 0xFF)
    , m_a((rgba >> 24) & 0xFF)
{
}

NsColor::~NsColor()
{
}

unsigned int NsColor::getRGB() const
{
    return (static_cast<unsigned int>(m_a) << 24) |
           (static_cast<unsigned int>(m_r) << 16) |
           (static_cast<unsigned int>(m_g) << 8) |
           static_cast<unsigned int>(m_b);
}

QColor NsColor::toQColor() const
{
    return QColor(m_r, m_g, m_b, m_a);
}

NsColor* NsColor::black = nullptr;
NsColor* NsColor::white = nullptr;

static struct NsColor_Init {
    NsColor_Init() {
        NsColor::black = new NsColor(0, 0, 0);
        NsColor::white = new NsColor(255, 255, 255);
    }
} _nscolor_init;
