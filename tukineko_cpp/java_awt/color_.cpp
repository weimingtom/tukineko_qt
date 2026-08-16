#include "color_.h"

Color_* Color_::black = new Color_(0, 0, 0);
Color_* Color_::white = new Color_(255, 255, 255);
Color_* Color_::red = new Color_(255, 0, 0);
Color_* Color_::green = new Color_(0, 255, 0);
Color_* Color_::blue = new Color_(0, 0, 255);
Color_* Color_::yellow = new Color_(255, 255, 0);
Color_* Color_::cyan = new Color_(0, 255, 255);
Color_* Color_::magenta = new Color_(255, 0, 255);
Color_* Color_::gray = new Color_(128, 128, 128);
Color_* Color_::lightGray = new Color_(192, 192, 192);
Color_* Color_::darkGray = new Color_(64, 64, 64);

Color_::Color_()
    : m_red(0), m_green(0), m_blue(0), m_alpha(255)
{
}

Color_::Color_(int r, int g, int b)
    : m_red(r), m_green(g), m_blue(b), m_alpha(255)
{
}

Color_::Color_(int r, int g, int b, int a)
    : m_red(r), m_green(g), m_blue(b), m_alpha(a)
{
}

Color_::Color_(int rgb)
    : m_red((rgb >> 16) & 0xFF)
    , m_green((rgb >> 8) & 0xFF)
    , m_blue(rgb & 0xFF)
    , m_alpha(255)
{
}

Color_::Color_(float r, float g, float b)
    : m_red(static_cast<int>(r * 255))
    , m_green(static_cast<int>(g * 255))
    , m_blue(static_cast<int>(b * 255))
    , m_alpha(255)
{
}

int Color_::getRed() const { return m_red; }
int Color_::getGreen() const { return m_green; }
int Color_::getBlue() const { return m_blue; }
int Color_::getAlpha() const { return m_alpha; }

int Color_::getRGB() const
{
    return (m_alpha << 24) | (m_red << 16) | (m_green << 8) | m_blue;
}

QColor Color_::toQColor() const
{
    return QColor(m_red, m_green, m_blue, m_alpha);
}
