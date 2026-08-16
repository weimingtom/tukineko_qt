#include "graphics_.h"
#include "image_.h"

Graphics_::Graphics_()
    : m_painter(nullptr)
{
    m_color = Qt::black;
    m_pen.setColor(m_color);
    m_brush.setColor(m_color);
    m_font.setFamily("Arial");
    m_font.setPixelSize(12);
}

Graphics_::~Graphics_()
{
}

void Graphics_::setPainter(QPainter* painter)
{
    m_painter = painter;
    if (m_painter) {
        m_painter->setPen(m_pen);
        m_painter->setBrush(m_brush);
        m_painter->setFont(m_font);
    }
}

QPainter* Graphics_::getPainter() const
{
    return m_painter;
}

void Graphics_::setColor(const QColor& color)
{
    m_color = color;
    m_pen.setColor(color);
    m_brush.setColor(color);
    if (m_painter) {
        m_painter->setPen(m_pen);
        m_painter->setBrush(m_brush);
    }
}

void Graphics_::setFont(const QFont& font)
{
    m_font = font;
    if (m_painter) {
        m_painter->setFont(m_font);
    }
}

void Graphics_::drawImage(Image_* img, int x, int y)
{
    if (m_painter && img) {
        m_painter->drawImage(x, y, *img->getImage());
    }
}

void Graphics_::drawImage(Image_* img, int x, int y, int w, int h)
{
    if (m_painter && img) {
        m_painter->drawImage(QRect(x, y, w, h), *img->getImage(), img->getImage()->rect());
    }
}

void Graphics_::drawString(const QString& str, int x, int y)
{
    if (m_painter) {
        m_painter->drawText(x, y + m_painter->fontMetrics().ascent(), str);
    }
}

void Graphics_::fillRect(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->fillRect(x, y, w, h, m_brush);
    }
}

void Graphics_::drawLine(int x1, int y1, int x2, int y2)
{
    if (m_painter) {
        m_painter->drawLine(x1, y1, x2, y2);
    }
}

void Graphics_::drawRect(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->drawRect(x, y, w, h);
    }
}

void Graphics_::drawRoundRect(int x, int y, int w, int h, int rx, int ry)
{
    if (m_painter) {
        m_painter->drawRoundedRect(x, y, w, h, rx, ry);
    }
}

void Graphics_::drawOval(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->drawEllipse(x, y, w, h);
    }
}

void Graphics_::fillOval(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->setBrush(m_brush);
        m_painter->drawEllipse(x, y, w, h);
    }
}

void Graphics_::clearRect(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->fillRect(x, y, w, h, Qt::transparent);
    }
}

void Graphics_::setClip(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->setClipRect(x, y, w, h);
    }
}
