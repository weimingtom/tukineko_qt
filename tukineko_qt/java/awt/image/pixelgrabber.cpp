#include "pixelgrabber.h"
#include <QImage>
#include <QDebug>

PixelGrabber::PixelGrabber(Image_* img, int x, int y, int w, int h, unsigned int* pixels, int offset, int scansize)
    : m_image(img)
    , m_x(x)
    , m_y(y)
    , m_width(w)
    , m_height(h)
    , m_pixels(pixels)
    , m_offset(offset)
    , m_scansize(scansize)
    , m_status(0)
{
}

PixelGrabber::~PixelGrabber()
{
}

bool PixelGrabber::grabPixels()
{
    if (!m_image || !m_image->m_bufferImage || !m_pixels) {
        m_status = -1;
        return false;
    }

    QImage* img = m_image->m_bufferImage;
    if (img->format() != QImage::Format_ARGB32 &&
        img->format() != QImage::Format_ARGB32_Premultiplied) {
        *img = img->convertToFormat(QImage::Format_ARGB32);
    }

    for (int row = 0; row < m_height; ++row) {
        for (int col = 0; col < m_width; ++col) {
            int srcX = m_x + col;
            int srcY = m_y + row;
            if (srcX >= 0 && srcX < img->width() && srcY >= 0 && srcY < img->height()) {
                m_pixels[(row + m_offset) * m_scansize / 4 + col] = img->pixel(srcX, srcY);
            }
        }
    }

    m_status = 0;
    return true;
}
