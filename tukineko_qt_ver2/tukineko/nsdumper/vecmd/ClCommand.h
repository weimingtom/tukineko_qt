#ifndef CLCOMMAND_H
#define CLCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class ClCommand : public VECommand
{
public:
    ClCommand();
    virtual ~ClCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // CLCOMMAND_H
