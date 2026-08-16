#ifndef MENUFULLCOMMAND_H
#define MENUFULLCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class MenufullCommand : public VECommand
{
public:
    MenufullCommand();
    virtual ~MenufullCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // MENUFULLCOMMAND_H
