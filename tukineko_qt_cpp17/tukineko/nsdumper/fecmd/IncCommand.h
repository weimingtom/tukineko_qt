#ifndef INCCOMMAND_H
#define INCCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class IncCommand : public FECommand
{
public:
    IncCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // INCCOMMAND_H
