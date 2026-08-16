#ifndef NSEFFECT_H
#define NSEFFECT_H

#include <QString>

class NsEffect
{
public:
    int type;
    int time;
    QString pattern;

    NsEffect();
    NsEffect(int type);
    NsEffect(int type, int time);
    NsEffect(int type, int time, const QString &pattern);
};

#endif // NSEFFECT_H
