#ifndef JUMMFCOMMAND_H
#define JUMMFCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class JumpfCommand : public FECommand
{
public:
    JumpfCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // JUMMFCOMMAND_H
