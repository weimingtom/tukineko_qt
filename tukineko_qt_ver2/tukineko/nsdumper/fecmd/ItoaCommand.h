#ifndef ITOACOMMAND_H
#define ITOACOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class ItoaCommand : public FECommand
{
public:
    ItoaCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ITOACOMMAND_H
