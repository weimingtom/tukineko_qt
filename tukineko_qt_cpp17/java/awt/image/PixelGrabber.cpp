#include "PixelGrabber.h"

namespace java {
namespace awt {
namespace image {

PixelGrabber::PixelGrabber(Image_* img, int x, int y, int w, int h, QVector<quint32>* pix, int off, int scansize)
{
    Q_UNUSED(img)
    Q_UNUSED(x)
    Q_UNUSED(y)
    Q_UNUSED(w)
    Q_UNUSED(h)
    Q_UNUSED(pix)
    Q_UNUSED(off)
    Q_UNUSED(scansize)
}

void PixelGrabber::grabPixels()
{
    // Implementation depends on specific needs
}

} // namespace image
} // namespace awt
} // namespace java
