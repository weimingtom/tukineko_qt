#ifndef JAVA_AWT_IMAGE_MEMORYIMAGESOURCE_H
#define JAVA_AWT_IMAGE_MEMORYIMAGESOURCE_H

#include <QByteArray>
#include <QVector>

namespace java {
namespace awt {
namespace image {

class MemoryImageSource {
public:
    int w;
    int h;
    QByteArray bytes;
    QVector<quint32> pix;

    MemoryImageSource(int w, int h, const QVector<quint32>& pix, int off, int scan);
};

} // namespace image
} // namespace awt
} // namespace java

#endif // JAVA_AWT_IMAGE_MEMORYIMAGESOURCE_H
