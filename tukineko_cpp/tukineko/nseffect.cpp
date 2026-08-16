#include "nseffect.h"

NsEffect::NsEffect()
    : type(0)
    , time(1000)
    , async(false)
{
}

void NsEffect::apply(Image_* src, Image_* dst)
{
    // Effect implementation
    // For now, just copy
    if (src && dst) {
        *dst = *src;
    }
}
