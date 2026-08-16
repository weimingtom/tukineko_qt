#ifndef SETWINDOWCOMMAND_H
#define SETWINDOWCOMMAND_H

#include "SECommand.h"

#include "nscripter.h"

class SetwindowCommand : public SECommand
{
public:
    SetwindowCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // SETWINDOWCOMMAND_H
