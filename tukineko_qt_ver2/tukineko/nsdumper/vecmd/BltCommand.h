#ifndef BLTCOMMAND_H
#define BLTCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class BltCommand : public VECommand
{
public:
    BltCommand();
    virtual ~BltCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // BLTCOMMAND_H
