#ifndef DSOUNDCOMMAND_H
#define DSOUNDCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class DsoundCommand : public SFCommand
{
public:
    DsoundCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DSOUNDCOMMAND_H
