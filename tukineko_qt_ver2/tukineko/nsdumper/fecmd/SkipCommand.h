#ifndef SKIPCOMMAND_H
#define SKIPCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class SkipCommand : public FECommand
{
public:
    SkipCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SKIPCOMMAND_H
