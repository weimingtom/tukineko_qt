#ifndef GOSUBCOMMAND_H
#define GOSUBCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class GosubCommand : public FECommand
{
public:
    GosubCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // GOSUBCOMMAND_H
