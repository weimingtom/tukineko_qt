#ifndef JAVA_AWT_IMAGE_H
#define JAVA_AWT_IMAGE_H

#include <QImage>

namespace java {
namespace awt {

class Graphics_;
class Panel_;

class Image_ {
public:
    QImage* m_bufferBmp;

    Image_();
    Image_(QImage* bufferBmp): m_bufferBmp(bufferBmp) {}
    virtual ~Image_();

    Graphics_* getGraphics();
    int getWidth(QObject* o = nullptr);
    int getHeight(QObject* o = nullptr);
};

} // namespace awt
} // namespace java

#endif // JAVA_AWT_IMAGE_H
