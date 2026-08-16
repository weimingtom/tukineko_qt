#ifndef WINDOWEFFECTCOMMAND_H
#define WINDOWEFFECTCOMMAND_H

#include "sfecommand.h"

#include "nscripter.h"

class WindoweffectCommand : public SFECommand
{
public:
    WindoweffectCommand();

    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // WINDOWEFFECTCOMMAND_H
