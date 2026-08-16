#ifndef BRCOMMAND_H
#define BRCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class BrCommand : public VECommand
{
public:
    BrCommand();
    virtual ~BrCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // BRCOMMAND_H
