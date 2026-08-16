#ifndef EFFECTBLANKCOMMAND_H
#define EFFECTBLANKCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class EffectblankCommand : public SFCommand
{
public:
    EffectblankCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // EFFECTBLANKCOMMAND_H
