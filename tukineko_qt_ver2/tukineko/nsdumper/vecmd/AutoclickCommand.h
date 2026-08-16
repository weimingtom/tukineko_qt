#ifndef AUTOCLICKCOMMAND_H
#define AUTOCLICKCOMMAND_H

#include "VECommand.h"
#include "nscripter.h"

class AutoclickCommand : public VECommand
{
public:
    AutoclickCommand();
    virtual ~AutoclickCommand();

    virtual bool check(const QString &str) override;
    virtual void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // AUTOCLICKCOMMAND_H
