#ifndef DWAVESTOPCOMMAND_H
#define DWAVESTOPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class DwavestopCommand : public VECommand
{
public:
    DwavestopCommand();
    virtual ~DwavestopCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DWAVESTOPCOMMAND_H
