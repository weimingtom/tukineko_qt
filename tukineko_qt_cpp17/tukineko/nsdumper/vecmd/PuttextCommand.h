#ifndef PUTTEXTCOMMAND_H
#define PUTTEXTCOMMAND_H

#include "VECommand.h"

namespace tukineko {

#include "nscripter.h"

class PuttextCommand : public VECommand
{
public:
    PuttextCommand();
    virtual ~PuttextCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

}

#endif // PUTTEXTCOMMAND_H
