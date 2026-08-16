#ifndef MEMORYIMAGESOURCE_H
#define MEMORYIMAGESOURCE_H

#include <QObject>

class MemoryImageSource
{
public:
    MemoryImageSource(int w, int h, unsigned int* pixels, int offset, int scan);
    virtual ~MemoryImageSource();

    int width() const { return m_width; }
    int height() const { return m_height; }
    unsigned int* pixels() const { return m_pixels; }
    int offset() const { return m_offset; }
    int scan() const { return m_scan; }

private:
    int m_width;
    int m_height;
    unsigned int* m_pixels;
    int m_offset;
    int m_scan;
};

#endif // MEMORYIMAGESOURCE_H
