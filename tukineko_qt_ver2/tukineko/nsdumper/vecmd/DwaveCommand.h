#ifndef DWAVECOMMAND_H
#define DWAVECOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class DwaveCommand : public VECommand
{
public:
    DwaveCommand();
    virtual ~DwaveCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DWAVECOMMAND_H
