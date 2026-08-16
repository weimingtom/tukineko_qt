#include "nseffect.h"

NsEffect::NsEffect()
    : type(0), time(0)
{
}

NsEffect::NsEffect(int _type)
    : type(_type)
{
}

NsEffect::NsEffect(int _type, int _time)
    : type(_type), time(_time)
{
}

NsEffect::NsEffect(int _type, int _time, const QString& _pattern)
    : type(_type), time(_time), pattern(_pattern)
{
}

NsEffect::~NsEffect()
{
}
