#ifndef UNDERLINECOMMAND_H
#define UNDERLINECOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class UnderlineCommand : public SFCommand
{
public:
    UnderlineCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // UNDERLINECOMMAND_H
