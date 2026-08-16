#ifndef ATOICOMMAND_H
#define ATOICOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class AtoiCommand : public FECommand
{
public:
    AtoiCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ATOICOMMAND_H
