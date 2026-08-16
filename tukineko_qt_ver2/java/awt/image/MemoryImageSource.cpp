#include "MemoryImageSource.h"

namespace java {
namespace awt {
namespace image {

MemoryImageSource::MemoryImageSource(int w, int h, const QVector<quint32>& pix, int off, int scan)
    : w(w)
    , h(h)
    , pix(pix)
{
    Q_UNUSED(off)
    Q_UNUSED(scan)
    bytes.resize(w * h * 4);
    for (int j = 0; j < h; ++j) {
        for (int i = 0; i < w; ++i) {
            quint32 pixel = pix[j * w + i];
            bytes[j * w * 4 + i * 4 + 0] = static_cast<char>((pixel >> 24) & 0xff);
            bytes[j * w * 4 + i * 4 + 1] = static_cast<char>((pixel >> 16) & 0xff);
            bytes[j * w * 4 + i * 4 + 2] = static_cast<char>((pixel >>  8) & 0xff);
            bytes[j * w * 4 + i * 4 + 3] = static_cast<char>((pixel >>  0) & 0xff);
        }
    }
}

} // namespace image
} // namespace awt
} // namespace java
