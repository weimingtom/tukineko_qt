#ifndef LOADGAMECOMMAND_H
#define LOADGAMECOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class LoadgameCommand : public FECommand
{
public:
    LoadgameCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LOADGAMECOMMAND_H
