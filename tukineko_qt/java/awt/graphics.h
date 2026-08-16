#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QPainter>
#include <QFont>
#include "component.h"
#include "color.h"
#include "image.h"
#include "fontmetrics.h"


class Graphics_
{
public:
    Graphics_();
    virtual ~Graphics_();

    void setPainter(QPainter* painter);

    void drawImage(Image_* i, int x, int y, Component* p);
    void setColor(Color_* c);
    void drawString(const QString& str, int x, int y);
    void fillRect(int x, int y, int w, int h);
    void drawRect(int x, int y, int w, int h);
    FontMetrics getFontMetrics();
    void setClip(int x, int y, int w, int h);

private:
    QPainter* m_painter;
    Color_* m_color;
    QFont m_font;
};

#endif // GRAPHICS_H
