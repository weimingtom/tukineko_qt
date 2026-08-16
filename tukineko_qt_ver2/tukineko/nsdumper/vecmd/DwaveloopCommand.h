#ifndef DWAVELOOPCOMMAND_H
#define DWAVELOOPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class DwaveloopCommand : public VECommand
{
public:
    DwaveloopCommand();
    virtual ~DwaveloopCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DWAVELOOPCOMMAND_H
