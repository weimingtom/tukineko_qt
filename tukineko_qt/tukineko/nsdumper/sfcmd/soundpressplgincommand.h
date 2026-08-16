#ifndef SOUNDPRESSPLGINCOMMAND_H
#define SOUNDPRESSPLGINCOMMAND_H

#include <QString>
#include "sfcommand.h"

class SoundpressplginCommand : public SFCommand
{
public:
    SoundpressplginCommand();
    virtual ~SoundpressplginCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SOUNDPRESSPLGINCOMMAND_H
