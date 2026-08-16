#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class AddCommand : public FECommand
{
public:
    AddCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ADDCOMMAND_H
