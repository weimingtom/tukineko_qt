#include "toolkit.h"
#include <QImage>
#include <QFile>
#include <QDebug>

Toolkit::Toolkit()
{
}

Toolkit* Toolkit::s_instance = nullptr;

Toolkit* Toolkit::getDefaultToolkit()
{
    if (!s_instance) {
        s_instance = new Toolkit();
    }
    return s_instance;
}

Image_* Toolkit::createImage(const QString& filename)
{
    Image_* img = new Image_();
    img->m_bufferImage = new QImage(filename);
    if (img->m_bufferImage->isNull()) {
        qDebug() << "Failed to load image:" << filename;
        delete img->m_bufferImage;
        img->m_bufferImage = nullptr;
    }
    return img;
}

Image_* Toolkit::createImage(const QByteArray& bytes)
{
    Image_* img = new Image_();
    img->m_bufferImage = new QImage();
    img->m_bufferImage->loadFromData(bytes);
    if (img->m_bufferImage->isNull()) {
        delete img->m_bufferImage;
        img->m_bufferImage = nullptr;
    }
    return img;
}

Image_* Toolkit::createImage(int w, int h, unsigned int* pixels, int offset, int scan)
{
    Q_UNUSED(offset);
    Q_UNUSED(scan);

    Image_* img = new Image_();
    img->m_bufferImage = new QImage(w, h, QImage::Format_ARGB32);

    if (pixels && img->m_bufferImage) {
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                img->m_bufferImage->setPixel(x, y, pixels[y * w + x]);
            }
        }
    }

    return img;
}
