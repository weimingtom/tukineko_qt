#ifndef NSEFFECT_H
#define NSEFFECT_H

#include "../java_awt/image_.h"

class NsEffect
{
public:
    NsEffect();
    
    int type;      // Effect type (0=none, 1=fade, 2=scroll, etc.)
    int time;      // Effect duration in milliseconds
    bool async;    // Async flag
    
    void apply(Image_* src, Image_* dst);
};

#endif // NSEFFECT_H
