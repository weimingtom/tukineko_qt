#ifndef NSCOLOR_H
#define NSCOLOR_H

#include <QtGlobal>

class NsColor
{
public:
    static NsColor white;
    static NsColor black;

    NsColor();
    NsColor(quint32 rgb);
    NsColor(quint32 r, quint32 g, quint32 b);
    NsColor(quint32 r, quint32 g, quint32 b, quint32 a);

    quint32 getRGB() const;

private:
    quint32 value;
};

#endif // NSCOLOR_H
