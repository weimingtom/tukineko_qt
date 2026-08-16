#include "NsEffect.h"

NsEffect::NsEffect()
{

}

NsEffect::NsEffect(int type)
    : type(type)
    , time(0)
    , pattern(QString())
{
}

NsEffect::NsEffect(int type, int time)
    : type(type)
    , time(time)
    , pattern(QString())
{
}

NsEffect::NsEffect(int type, int time, const QString &pattern)
    : type(type)
    , time(time)
    , pattern(pattern)
{
}
