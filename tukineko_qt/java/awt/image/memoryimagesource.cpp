#include "memoryimagesource.h"

MemoryImageSource::MemoryImageSource(int w, int h, unsigned int* pixels, int offset, int scan)
    : m_width(w)
    , m_height(h)
    , m_pixels(pixels)
    , m_offset(offset)
    , m_scan(scan)
{
}

MemoryImageSource::~MemoryImageSource()
{
}
