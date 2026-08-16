#include "Color_.h"

namespace java {
namespace awt {

Color_::Color_()
    : color_(Qt::black)
{
}

Color_::Color_(int r, int g, int b)
    : color_(r, g, b)
{
}

Color_::Color_(quint32 rgba, bool hasalpha)
{
    if (hasalpha) {
        int a = static_cast<int>((rgba >> 24) & 0xff);
        int r = static_cast<int>((rgba >> 16) & 0xff);
        int g = static_cast<int>((rgba >>  8) & 0xff);
        int b = static_cast<int>((rgba >>  0) & 0xff);
        color_ = QColor(r, g, b, a);
    } else {
        int r = static_cast<int>((rgba >> 16) & 0xff);
        int g = static_cast<int>((rgba >>  8) & 0xff);
        int b = static_cast<int>((rgba >>  0) & 0xff);
        color_ = QColor(r, g, b);
    }
}

Color_ Color_::black = Color_(0, 0, 0);
Color_ Color_::white = Color_(0xff, 0xff, 0xff);

} // namespace awt
} // namespace java
