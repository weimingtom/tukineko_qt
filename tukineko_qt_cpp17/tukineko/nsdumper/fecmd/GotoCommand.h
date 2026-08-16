#ifndef GOTOCOMMAND_H
#define GOTOCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class GotoCommand : public FECommand
{
public:
    GotoCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // GOTOCOMMAND_H
