#ifndef SETCURSORCOMMAND_H
#define SETCURSORCOMMAND_H

#include "SECommand.h"

class SetcursorCommand : public SECommand
{
public:
    SetcursorCommand();
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SETCURSORCOMMAND_H
