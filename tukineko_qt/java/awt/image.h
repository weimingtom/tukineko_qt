#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include "component.h"

class Graphics_;

class Image_
{
public:
    QImage* m_bufferImage;

    Image_();
    virtual ~Image_();

    Graphics_* getGraphics();
    int getWidth();
    int getHeight();
    int getWidth(void* o);
    int getHeight(void* o);
};

#endif // IMAGE_H
