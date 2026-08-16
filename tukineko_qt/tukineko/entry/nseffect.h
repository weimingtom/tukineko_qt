#ifndef NSEFFECT_H
#define NSEFFECT_H

#include <QString>

class NsEffect
{
public:
    NsEffect();
    NsEffect(int type);
    NsEffect(int type, int time);
    NsEffect(int type, int time, const QString& pattern);
    virtual ~NsEffect();

    int type;
    int time;
    QString pattern;
};

#endif // NSEFFECT_H
