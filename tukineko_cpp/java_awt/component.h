#ifndef COMPONENT_H
#define COMPONENT_H

#include <QWidget>
#include <QImage>
#include "color_.h"
#include "image_.h"

class Component
{
public:
    Component();
    virtual ~Component();
    
    int getWidth() const;
    int getHeight() const;
    void setSize(int w, int h);
    void setLocation(int x, int y);
    void setBackground(Color_* color);
    Color_* getBackground() const;
    void setForeground(Color_* color);
    Color_* getForeground() const;
    virtual void paint(Graphics_* g) = 0;
    
protected:
    int m_width;
    int m_height;
    int m_x;
    int m_y;
    Color_* m_background;
    Color_* m_foreground;
};

#endif // COMPONENT_H
