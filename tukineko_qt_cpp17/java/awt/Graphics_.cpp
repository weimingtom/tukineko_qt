#include "Graphics_.h"
#include "Image_.h"
#include "Panel_.h"
#include "FontMetrics.h"

namespace java {
namespace awt {

Graphics_::Graphics_()
    : m_font("SimSun", 10, QFont::Normal)
    , m_painter(nullptr)
{
}

Graphics_::~Graphics_()
{
    if (m_painter) {
        m_painter->end();
        delete m_painter;
    }
}

void Graphics_::drawImage(Image_* i, int x, int y, Panel_* p)
{
    Q_UNUSED(p)
    if (m_painter && i && i->m_bufferBmp) {
        if (x == 0 && y == 0) {
            m_painter->drawImage(x, y, *i->m_bufferBmp, 0, 0, 320, 240);
        } else {
            m_painter->drawImage(x, y, *i->m_bufferBmp);
        }
    }
}

void Graphics_::setColor(Color_* c)
{
    if (c) {
        m_color = *c;
        if (m_painter) {
            m_painter->setPen(c->color_);
            m_painter->setBrush(c->color_);
        }
    }
}

void Graphics_::drawString(const QString& str, int x, int y)
{
    if (m_painter) {
        m_painter->setFont(m_font);
        m_painter->setPen(m_color.color_);
        m_painter->drawText(x, y, str);
    }
}

void Graphics_::fillRect(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->fillRect(x, y, w, h, m_color.color_);
    }
}

FontMetrics* Graphics_::getFontMetrics()
{
    FontMetrics* fm = new FontMetrics();
    fm->m_painter = m_painter;
    fm->m_font = m_font;
    return fm;
}

void Graphics_::setClip(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->setClipRect(x, y, w, h);
    }
}

void Graphics_::drawRect(int x, int y, int w, int h)
{
    if (m_painter) {
        m_painter->setPen(m_color.color_);
        m_painter->drawRect(x, y, w, h);
    }
}

} // namespace awt
} // namespace java
