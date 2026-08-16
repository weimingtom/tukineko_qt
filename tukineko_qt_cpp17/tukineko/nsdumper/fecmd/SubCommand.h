#ifndef SUBCOMMAND_H
#define SUBCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class SubCommand : public FECommand
{
public:
    SubCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SUBCOMMAND_H
