#ifndef STRALIASCOMMAND_H
#define STRALIASCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class StraliasCommand : public SFCommand
{
public:
    StraliasCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // STRALIASCOMMAND_H
