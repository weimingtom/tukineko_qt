#ifndef IFCOMMAND_H
#define IFCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class IfCommand : public FECommand
{
public:
    IfCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // IFCOMMAND_H
