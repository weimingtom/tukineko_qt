#ifndef RMENUCOMMAND_H
#define RMENUCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class RmenuCommand : public SFCommand
{
public:
    RmenuCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // RMENUCOMMAND_H
