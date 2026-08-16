#ifndef COLOR__H
#define COLOR__H

#include <QColor>

class Color_
{
public:
    Color_();
    Color_(int r, int g, int b);
    Color_(int r, int g, int b, int a);
    Color_(int rgb);
    Color_(float r, float g, float b);
    
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    int getAlpha() const;
    int getRGB() const;
    QColor toQColor() const;
    
    static Color_* black;
    static Color_* white;
    static Color_* red;
    static Color_* green;
    static Color_* blue;
    static Color_* yellow;
    static Color_* cyan;
    static Color_* magenta;
    static Color_* gray;
    static Color_* lightGray;
    static Color_* darkGray;

private:
    int m_red;
    int m_green;
    int m_blue;
    int m_alpha;
};

#endif // COLOR__H
