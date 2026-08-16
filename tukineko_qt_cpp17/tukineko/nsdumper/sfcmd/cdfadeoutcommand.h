#ifndef CDFADEOUTCOMMAND_H
#define CDFADEOUTCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class CdfadeoutCommand : public SFCommand
{
public:
    CdfadeoutCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // CDFADEOUTCOMMAND_H
