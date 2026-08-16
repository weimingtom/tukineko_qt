#ifndef NSSPRITE_H
#define NSSPRITE_H

#include "../java_awt/image_.h"

class NsSprite
{
public:
    NsSprite();
    
    int num;       // Sprite number
    Image_* img;   // Sprite image
    int x, y;      // Position
    int z;         // Z-order
    bool visible;  // Visibility flag
    int transparency;  // Transparency 0-255
};

#endif // NSSPRITE_H
