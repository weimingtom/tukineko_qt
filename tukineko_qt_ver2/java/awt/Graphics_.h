#ifndef JAVA_AWT_GRAPHICS_H
#define JAVA_AWT_GRAPHICS_H

#include <QPainter>
#include <QFont>
#include <QFontMetrics>
#include <QString>
#include "Color_.h"

namespace java {
namespace awt {

class Image_;
class Panel_;
class FontMetrics;

class Graphics_ {
public:
    QFont m_font;
    QPainter* m_painter;
    Color_ m_color;

    Graphics_();
    ~Graphics_();

    void drawImage(Image_* i, int x, int y, Panel_* p = nullptr);
    void setColor(Color_* c);
    void drawString(const QString& str, int x, int y);
    void fillRect(int x, int y, int w, int h);
    FontMetrics* getFontMetrics();
    void setClip(int x, int y, int w, int h);
    void drawRect(int x, int y, int w, int h);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_GRAPHICS_H
