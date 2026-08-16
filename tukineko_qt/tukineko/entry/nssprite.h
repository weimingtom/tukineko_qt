#ifndef NSSPRITE_H
#define NSSPRITE_H

#include <QString>

class NsSprite
{
public:
    NsSprite();
    virtual ~NsSprite();

    QString image;
    int x;
    int y;
    int alpha;
    bool visible;
};

#endif // NSSPRITE_H
