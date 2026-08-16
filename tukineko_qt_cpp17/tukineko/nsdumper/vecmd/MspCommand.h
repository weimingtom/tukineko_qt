#ifndef MSPCOMMAND_H
#define MSPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class MspCommand : public VECommand
{
public:
    MspCommand();
    virtual ~MspCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MSPCOMMAND_H
