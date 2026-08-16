#ifndef BGALIACOMMAND_H
#define BGALIACOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class BgaliaCommand : public SFCommand
{
public:
    BgaliaCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // BGALIACOMMAND_H
