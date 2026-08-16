#include "image.h"
#include "graphics.h"

Image_::Image_()
    : m_bufferImage(nullptr)
{
}

Image_::~Image_()
{
    if (m_bufferImage) {
        delete m_bufferImage;
        m_bufferImage = nullptr;
    }
}

Graphics_* Image_::getGraphics()
{
    Graphics_* g = new Graphics_();
    if (m_bufferImage) {
        // Note: QPainter needs to be created with the image as paint device
        // This is a simplified implementation
        QPainter* painter = new QPainter(m_bufferImage);
        g->setPainter(painter);
    }
    return g;
}

int Image_::getWidth()
{
    if (m_bufferImage) {
        return m_bufferImage->width();
    }
    return 0;
}

int Image_::getHeight()
{
    if (m_bufferImage) {
        return m_bufferImage->height();
    }
    return 0;
}

int Image_::getWidth(void* o)
{
    Q_UNUSED(o);
    return getWidth();
}

int Image_::getHeight(void* o)
{
    Q_UNUSED(o);
    return getHeight();
}
