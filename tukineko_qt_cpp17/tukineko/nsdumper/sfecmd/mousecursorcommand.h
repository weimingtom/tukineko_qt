#ifndef MOUSECURSORCOMMAND_H
#define MOUSECURSORCOMMAND_H

#include "sfecommand.h"

#include "nscripter.h"

class MousecursorCommand : public SFECommand
{
public:
    MousecursorCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MOUSECURSORCOMMAND_H
