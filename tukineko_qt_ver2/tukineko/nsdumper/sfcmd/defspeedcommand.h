#ifndef DEFSPEEDCOMMAND_H
#define DEFSPEEDCOMMAND_H

#include "sfcommand.h"

#include "nscripter.h"

class DefSpeedCommand : public SFCommand
{
public:
    DefSpeedCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DEFSPEEDCOMMAND_H
