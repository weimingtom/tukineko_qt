#ifndef JAVA_AWT_IMAGE_PIXELGRABBER_H
#define JAVA_AWT_IMAGE_PIXELGRABBER_H

#include "../Image_.h"
#include <QVector>

namespace java {
namespace awt {
namespace image {

class PixelGrabber {
public:
    PixelGrabber(Image_* img, int x, int y, int w, int h, QVector<quint32>* pix, int off, int scansize);

    void grabPixels();
};

} // namespace image
} // namespace awt
} // namespace java

#endif // JAVA_AWT_IMAGE_PIXELGRABBER_H
