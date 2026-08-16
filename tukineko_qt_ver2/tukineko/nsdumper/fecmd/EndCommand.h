#ifndef ENDCOMMAND_H
#define ENDCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class EndCommand : public FECommand
{
public:
    EndCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ENDCOMMAND_H
