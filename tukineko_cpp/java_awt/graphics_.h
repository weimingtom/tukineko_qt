#ifndef GRAPHICS__H
#define GRAPHICS__H

#include <QPainter>
#include <QColor>
#include <QFont>
#include <QRect>
#include <QImage>
#include <QPen>
#include <QBrush>

class Image_;

class Graphics_
{
public:
    Graphics_();
    ~Graphics_();
    
    void setColor(const QColor& color);
    void setFont(const QFont& font);
    void drawImage(Image_* img, int x, int y);
    void drawImage(Image_* img, int x, int y, int w, int h);
    void drawString(const QString& str, int x, int y);
    void fillRect(int x, int y, int w, int h);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawRect(int x, int y, int w, int h);
    void drawRoundRect(int x, int y, int w, int h, int rx, int ry);
    void drawOval(int x, int y, int w, int h);
    void fillOval(int x, int y, int w, int h);
    void clearRect(int x, int y, int w, int h);
    void setPainter(QPainter* painter);
    QPainter* getPainter() const;
    void setClip(int x, int y, int w, int h);
    
    // For internal use
    void setNativePainter(QPainter* p) { m_painter = p; }

private:
    QPainter* m_painter;
    QPen m_pen;
    QBrush m_brush;
    QFont m_font;
    QColor m_color;
};

#endif // GRAPHICS__H
