#include "Toolkit.h"
#include <QImageReader>

namespace java {
namespace awt {

Toolkit* Toolkit::m_instance = nullptr;

Toolkit::Toolkit()
{
}

Toolkit* Toolkit::getDefaultToolkit()
{
    if (!m_instance) {
        m_instance = new Toolkit();
    }
    return m_instance;
}

Image_* Toolkit::createImage(image::MemoryImageSource* src)
{
    if (!src) {
        return nullptr;
    }
    Image_* result = new Image_();
    result->m_bufferBmp = new QImage(src->w, src->h, QImage::Format_ARGB32);
    for (int j = 0; j < src->h; ++j) {
        for (int i = 0; i < src->w; ++i) {
            quint32 p = src->pix[j * src->w + i];
            int a = static_cast<int>((p >> 24) & 0xff);
            int r = static_cast<int>((p >> 16) & 0xff);
            int g = static_cast<int>((p >>  8) & 0xff);
            int b = static_cast<int>((p >>  0) & 0xff);
            result->m_bufferBmp->setPixelColor(i, j, QColor(r, g, b, a));
        }
    }
    return result;
}

Image_* Toolkit::createImage(const QString& name)
{
    Image_* result = new Image_();
    result->m_bufferBmp = new QImage(name);
    return result;
}

Image_* Toolkit::createImage(const QByteArray& bytes)
{
    Image_* result = new Image_();
    result->m_bufferBmp = new QImage();
    result->m_bufferBmp->loadFromData(bytes);
    return result;
}

} // namespace awt
} // namespace java
