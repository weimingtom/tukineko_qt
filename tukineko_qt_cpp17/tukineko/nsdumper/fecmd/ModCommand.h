#ifndef MODCOMMAND_H
#define MODCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class ModCommand : public FECommand
{
public:
    ModCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MODCOMMAND_H
