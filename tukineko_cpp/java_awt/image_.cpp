#include "image_.h"
#include "graphics_.h"

Image_::Image_()
    : m_image(nullptr)
    , m_pixmap(nullptr)
    , m_graphics(nullptr)
{
}

Image_::Image_(int width, int height)
    : m_image(new QImage(width, height, QImage::Format_ARGB32))
    , m_pixmap(new QPixmap(width, height))
    , m_graphics(nullptr)
{
    m_image->fill(0);
}

Image_::Image_(const QString& filePath)
    : m_image(new QImage(filePath))
    , m_pixmap(new QPixmap(filePath))
    , m_graphics(nullptr)
{
}

Image_::Image_(const QImage& image)
    : m_image(new QImage(image))
    , m_pixmap(new QPixmap(QPixmap::fromImage(image)))
    , m_graphics(nullptr)
{
}

Image_::~Image_()
{
    if (m_graphics) {
        delete m_graphics;
    }
    if (m_pixmap) {
        delete m_pixmap;
    }
    if (m_image) {
        delete m_image;
    }
}

int Image_::getWidth() const
{
    return m_image ? m_image->width() : 0;
}

int Image_::getHeight() const
{
    return m_image ? m_image->height() : 0;
}

QImage* Image_::getImage() const
{
    return m_image;
}

QPixmap* Image_::getPixmap() const
{
    return m_pixmap;
}

Graphics_* Image_::getGraphics()
{
    if (!m_graphics && m_image) {
        m_graphics = new Graphics_();
        // Note: QPainter requires a QPaintDevice, we can't directly use it on QImage
        // In actual implementation, you'd need to create a QPixmap for painting
    }
    return m_graphics;
}

void Image_::flush()
{
    // QImage doesn't need explicit flushing
}

bool Image_::isNull() const
{
    return !m_image || m_image->isNull();
}

void Image_::setPixel(int x, int y, uint pixel)
{
    if (m_image && x >= 0 && x < m_image->width() && y >= 0 && y < m_image->height()) {
        m_image->setPixel(x, y, pixel);
    }
}

uint Image_::pixel(int x, int y) const
{
    if (m_image && x >= 0 && x < m_image->width() && y >= 0 && y < m_image->height()) {
        return m_image->pixel(x, y);
    }
    return 0;
}

void Image_::fill(uint color)
{
    if (m_image) {
        m_image->fill(color);
    }
}

Image_* Image_::createImage(const QString& filePath)
{
    return new Image_(filePath);
}

Image_* Image_::createImage(int width, int height)
{
    return new Image_(width, height);
}
