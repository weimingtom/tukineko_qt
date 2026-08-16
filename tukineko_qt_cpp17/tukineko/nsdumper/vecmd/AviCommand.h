#ifndef AVICOMMAND_H
#define AVICOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class AviCommand : public VECommand
{
public:
    AviCommand();
    virtual ~AviCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // AVICOMMAND_H
