#ifndef COLOR_H
#define COLOR_H

#include <QColor>

class Color_
{
public:
    QColor color_;

    Color_();
    Color_(int r, int g, int b);
    Color_(unsigned int rgba, bool hasalpha);

    static Color_* black;
    static Color_* white;
};

#endif // COLOR_H
