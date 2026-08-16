#ifndef EFFECTCOMMAND_H
#define EFFECTCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class EffectCommand : public SFCommand
{
public:
    EffectCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // EFFECTCOMMAND_H
