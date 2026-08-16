#include "graphics.h"
#include <QPainter>
#include <QFont>
#include <QRect>


Graphics_::Graphics_()
    : m_painter(nullptr)
    , m_color(nullptr)
{
    m_font = QFont("SimSun", 10);
}

Graphics_::~Graphics_()
{
}

void Graphics_::setPainter(QPainter* painter)
{
    m_painter = painter;
    if (m_painter) {
        m_painter->setFont(m_font);
    }
}

void Graphics_::drawImage(Image_* i, int x, int y, Component* p)
{
    if (m_painter && i && i->m_bufferImage) {
        if (x == 0 && y == 0) {
            m_painter->drawImage(x, y, *i->m_bufferImage, 320, 240);
        } else {
            m_painter->drawImage(x, y, *i->m_bufferImage);
        }
    }
}

void Graphics_::setColor(Color_* c)
{
    m_color = c;
    if (m_painter && c) {
        m_painter->setPen(c->color_);
    }
}

void Graphics_::drawString(const QString& str, int x, int y)
{
    if (m_painter && !str.isEmpty()) {
        if (m_color) {
            m_painter->setPen(m_color->color_);
        }
        m_painter->drawText(x, y, str);
    }
}

void Graphics_::fillRect(int x, int y, int w, int h)
{
    if (m_painter) {
        if (m_color) {
            m_painter->fillRect(x, y, w, h, m_color->color_);
        } else {
            m_painter->fillRect(x, y, w, h, Qt::black);
        }
    }
}

void Graphics_::drawRect(int x, int y, int w, int h)
{
    if (m_painter) {
        if (m_color) {
            m_painter->setPen(m_color->color_);
        }
        m_painter->drawRect(x, y, w, h);
    }
}

FontMetrics Graphics_::getFontMetrics()
{
    FontMetrics fm;
    fm.setFont(m_font);
    fm.setPainter(m_painter);
    return fm;
}

void Graphics_::setClip(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->setClipRect(x, y, w, h);
    }
}
