#ifndef MOVCOMMAND_H
#define MOVCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class MovCommand : public FECommand
{
public:
    MovCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MOVCOMMAND_H
