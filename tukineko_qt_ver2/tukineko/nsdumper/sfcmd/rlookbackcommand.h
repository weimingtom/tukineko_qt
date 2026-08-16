#ifndef RLOOKBACKCOMMAND_H
#define RLOOKBACKCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class RlookbackCommand : public SFCommand
{
public:
    RlookbackCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // RLOOKBACKCOMMAND_H
