#ifndef NSBUTTON_H
#define NSBUTTON_H

#include "../java_awt/image_.h"

class NsButton
{
public:
    NsButton();
    
    int no;        // Button number
    int x, y;      // Position
    int width, height;  // Size
    int u, v;      // UV coordinates for sprites
    Image_* img;   // Button image
    Image_* imgHover;   // Hover image
    Image_* imgClick;   // Clicked image
    bool visible;
    bool enabled;
};

#endif // NSBUTTON_H
