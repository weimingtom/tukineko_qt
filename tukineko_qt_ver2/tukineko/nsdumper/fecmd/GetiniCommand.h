#ifndef GETINICOMMAND_H
#define GETINICOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class GetiniCommand : public FECommand
{
public:
    GetiniCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // GETINICOMMAND_H
