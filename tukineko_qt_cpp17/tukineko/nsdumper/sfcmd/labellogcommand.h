#ifndef LABELLOGCOMMAND_H
#define LABELLOGCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class LabellogCommand : public SFCommand
{
public:
    LabellogCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LABELLOGCOMMAND_H
