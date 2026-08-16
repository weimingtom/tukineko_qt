#ifndef CMPCOMMAND_H
#define CMPCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class CmpCommand : public FECommand
{
public:
    CmpCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // CMPCOMMAND_H
