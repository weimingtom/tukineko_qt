#ifndef RNDCOMMAND_H
#define RNDCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class RndCommand : public FECommand
{
public:
    RndCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // RNDCOMMAND_H
