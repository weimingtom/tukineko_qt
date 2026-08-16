#ifndef ROFFCOMMAND_H
#define ROFFCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class RoffCommand : public SFCommand
{
public:
    RoffCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ROFFCOMMAND_H
