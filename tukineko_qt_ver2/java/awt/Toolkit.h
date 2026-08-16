#ifndef JAVA_AWT_TOOLKIT_H
#define JAVA_AWT_TOOLKIT_H

#include "Image_.h"
#include "image/MemoryImageSource.h"
#include <QString>
#include <QByteArray>

namespace java {
namespace awt {

class Toolkit {
private:
    Toolkit();

    static Toolkit* m_instance;

public:
    static Toolkit* getDefaultToolkit();

    Image_* createImage(image::MemoryImageSource* src);
    Image_* createImage(const QString& name);
    Image_* createImage(const QByteArray& bytes);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_TOOLKIT_H
