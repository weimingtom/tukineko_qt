#ifndef GETREGCOMMAND_H
#define GETREGCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class GetregCommand : public FECommand
{
public:
    GetregCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // GETREGCOMMAND_H
