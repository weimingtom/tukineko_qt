#include "Image_.h"
#include "Graphics_.h"

namespace java {
namespace awt {

Image_::Image_()
    : m_bufferBmp(nullptr)
{
}

Image_::~Image_()
{
    delete m_bufferBmp;
}

Graphics_* Image_::getGraphics()
{
    Graphics_* g = new Graphics_();
    if (m_bufferBmp) {
        g->m_painter = new QPainter(m_bufferBmp);
    }
    return g;
}

int Image_::getWidth(QObject* o)
{
    Q_UNUSED(o)
    if (m_bufferBmp) {
        return m_bufferBmp->width();
    }
    return 0;
}

int Image_::getHeight(QObject* o)
{
    Q_UNUSED(o)
    if (m_bufferBmp) {
        return m_bufferBmp->height();
    }
    return 0;
}

} // namespace awt
} // namespace java
