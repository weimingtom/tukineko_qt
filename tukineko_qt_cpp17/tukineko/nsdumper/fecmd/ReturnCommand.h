#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class ReturnCommand : public FECommand
{
public:
    ReturnCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // RETURNCOMMAND_H
