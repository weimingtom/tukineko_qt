#ifndef LSPHCOMMAND_H
#define LSPHCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class LsphCommand : public VECommand
{
public:
    LsphCommand();
    virtual ~LsphCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LSPHCOMMAND_H
