#ifndef GLOBALONCOMMAND_H
#define GLOBALONCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class GlobalonCommand : public SFCommand
{
public:
    GlobalonCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // GLOBALONCOMMAND_H
