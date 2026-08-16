#ifndef SOUNDPRESSPLGINCOMMAND_H
#define SOUNDPRESSPLGINCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class SoundpressplginCommand : public SFCommand
{
public:
    SoundpressplginCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SOUNDPRESSPLGINCOMMAND_H
