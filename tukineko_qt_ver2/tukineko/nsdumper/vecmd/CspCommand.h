#ifndef CSPCOMMAND_H
#define CSPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class CspCommand : public VECommand
{
public:
    CspCommand();
    virtual ~CspCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // CSPCOMMAND_H
