#ifndef TIMECOMMAND_H
#define TIMECOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class TimeCommand : public FECommand
{
public:
    TimeCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // TIMECOMMAND_H
