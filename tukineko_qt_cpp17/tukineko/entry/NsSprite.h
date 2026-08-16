#ifndef NSPRITE_H
#define NSPRITE_H

#include <QString>

class NsSprite
{
public:
    QString image;
    int x;
    int y;
    int alpha;
    bool visible;

    NsSprite();
};

#endif // NSPRITE_H
