#ifndef NUMALIASCOMMAND_H
#define NUMALIASCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class NumaliasCommand : public SFCommand
{
public:
    NumaliasCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // NUMALIASCOMMAND_H
