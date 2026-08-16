#ifndef LDCOMMAND_H
#define LDCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class LdCommand : public VECommand
{
public:
    LdCommand();
    virtual ~LdCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LDCOMMAND_H
