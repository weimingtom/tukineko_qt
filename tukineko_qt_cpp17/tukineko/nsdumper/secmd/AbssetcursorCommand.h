#ifndef ABSSETCURSORCOMMAND_H
#define ABSSETCURSORCOMMAND_H

#include "SECommand.h"

#include "nscripter.h"

class AbssetcursorCommand : public SECommand
{
public:
    AbssetcursorCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // ABSSETCURSORCOMMAND_H
