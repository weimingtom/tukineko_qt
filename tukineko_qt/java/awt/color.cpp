#include "color.h"

Color_::Color_()
    : color_(Qt::black)
{
}

Color_::Color_(int r, int g, int b)
    : color_(r, g, b, 255)
{
}

Color_::Color_(unsigned int rgba, bool hasalpha)
{
    if (hasalpha) {
        int a = (rgba >> 24) & 0xff;
        int r = (rgba >> 16) & 0xff;
        int g = (rgba >> 8) & 0xff;
        int b = (rgba >> 0) & 0xff;
        color_ = QColor(r, g, b, a);
    } else {
        int r = (rgba >> 16) & 0xff;
        int g = (rgba >> 8) & 0xff;
        int b = (rgba >> 0) & 0xff;
        color_ = QColor(r, g, b, 255);
    }
}

Color_* Color_::black = nullptr;
Color_* Color_::white = nullptr;

// Initialize static members after color class is complete
static struct Color_Init {
    Color_Init() {
        Color_::black = new Color_(0, 0, 0);
        Color_::white = new Color_(0xff, 0xff, 0xff);
    }
} _color_init;
