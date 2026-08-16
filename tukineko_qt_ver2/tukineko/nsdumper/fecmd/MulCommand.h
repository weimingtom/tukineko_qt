#ifndef MULCOMMAND_H
#define MULCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class MulCommand : public FECommand
{
public:
    MulCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MULCOMMAND_H
