#ifndef JUMPBCOMMAND_H
#define JUMPBCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class JumpbCommand : public FECommand
{
public:
    JumpbCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // JUMPBCOMMAND_H
