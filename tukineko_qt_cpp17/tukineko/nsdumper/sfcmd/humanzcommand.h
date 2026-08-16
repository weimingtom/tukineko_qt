#ifndef HUMANZCOMMAND_H
#define HUMANZCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class HumanzCommand : public SFCommand
{
public:
    HumanzCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // HUMANZCOMMAND_H
