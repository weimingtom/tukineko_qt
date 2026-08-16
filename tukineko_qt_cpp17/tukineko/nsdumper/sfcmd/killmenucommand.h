#ifndef KILLMENUCOMMAND_H
#define KILLMENUCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class KillmenuCommand : public SFCommand
{
public:
    KillmenuCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // KILLMENUCOMMAND_H
