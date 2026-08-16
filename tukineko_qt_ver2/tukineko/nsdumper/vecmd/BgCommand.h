#ifndef BGCOMMAND_H
#define BGCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class BgCommand : public VECommand
{
public:
    BgCommand();
    virtual ~BgCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // BGCOMMAND_H
