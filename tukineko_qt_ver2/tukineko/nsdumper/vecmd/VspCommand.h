#ifndef VSPCOMMAND_H
#define VSPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class VspCommand : public VECommand
{
public:
    VspCommand();
    virtual ~VspCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // VSPCOMMAND_H
