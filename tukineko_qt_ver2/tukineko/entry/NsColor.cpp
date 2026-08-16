#include "NsColor.h"

NsColor NsColor::white = NsColor(255, 255, 255);
NsColor NsColor::black = NsColor(0, 0, 0);

NsColor::NsColor()
    : value(0xff000000 | 0)
{
}

NsColor::NsColor(quint32 rgb)
    : value(0xff000000 | rgb)
{
}

NsColor::NsColor(quint32 r, quint32 g, quint32 b)
    : NsColor(r, g, b, 255)
{
}

NsColor::NsColor(quint32 r, quint32 g, quint32 b, quint32 a)
    : value(((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | ((b & 0xFF) << 0))
{
}

quint32 NsColor::getRGB() const
{
    return value;
}
