#ifndef LSPCOMMAND_H
#define LSPCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class LspCommand : public VECommand
{
public:
    LspCommand();
    virtual ~LspCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // LSPCOMMAND_H
