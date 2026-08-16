#ifndef NSACOMMAND_H
#define NSACOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class NsaCommand : public SFCommand
{
public:
    NsaCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // NSACOMMAND_H
