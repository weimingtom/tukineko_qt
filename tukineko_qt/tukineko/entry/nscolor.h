#ifndef NSCOLOR_H
#define NSCOLOR_H

#include <QColor>

class NsColor
{
public:
    NsColor();
    NsColor(int r, int g, int b, int a = 255);
    NsColor(unsigned int rgba);
    virtual ~NsColor();

    int getR() const { return m_r; }
    int getG() const { return m_g; }
    int getB() const { return m_b; }
    int getA() const { return m_a; }
    unsigned int getRGB() const;

    QColor toQColor() const;

    static NsColor* black;
    static NsColor* white;

private:
    int m_r, m_g, m_b, m_a;
};

#endif // NSCOLOR_H
