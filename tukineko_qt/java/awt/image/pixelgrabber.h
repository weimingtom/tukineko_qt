#ifndef PIXELGRABBER_H
#define PIXELGRABBER_H

//#include <QObject>
#include "image.h"

class PixelGrabber //: public QObject
{
//    Q_OBJECT

public:
    PixelGrabber(Image_* img, int x, int y, int w, int h, unsigned int* pixels, int offset, int scansize);
    virtual ~PixelGrabber();

    bool grabPixels();
    int status() const { return m_status; }

//signals:
//    void imageGrabbed();

private:
    Image_* m_image;
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    unsigned int* m_pixels;
    int m_offset;
    int m_scansize;
    int m_status;
};

#endif // PIXELGRABBER_H
