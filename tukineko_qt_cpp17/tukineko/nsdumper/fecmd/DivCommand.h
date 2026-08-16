#ifndef DIVCOMMAND_H
#define DIVCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class DivCommand : public FECommand
{
public:
    DivCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // DIVCOMMAND_H
