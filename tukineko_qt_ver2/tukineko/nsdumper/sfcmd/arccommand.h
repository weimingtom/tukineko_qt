#ifndef ARCCOMMAND_H
#define ARCCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class ArcCommand : public SFCommand
{
public:
    ArcCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ARCCOMMAND_H
