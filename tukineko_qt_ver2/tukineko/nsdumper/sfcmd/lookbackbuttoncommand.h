#ifndef LOOKBACKBUTTONCOMMAND_H
#define LOOKBACKBUTTONCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class LookbackbuttonCommand : public SFCommand
{
public:
    LookbackbuttonCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LOOKBACKBUTTONCOMMAND_H
