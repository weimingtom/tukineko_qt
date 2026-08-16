#ifndef NEGACOMMAND_H
#define NEGACOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class NegaCommand : public VECommand
{
public:
    NegaCommand();
    virtual ~NegaCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // NEGACOMMAND_H
