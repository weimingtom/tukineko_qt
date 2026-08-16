#ifndef LOOKBACKCOLORCOMMAND_H
#define LOOKBACKCOLORCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class LookbackcolorCommand : public SFCommand
{
public:
    LookbackcolorCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LOOKBACKCOLORCOMMAND_H
