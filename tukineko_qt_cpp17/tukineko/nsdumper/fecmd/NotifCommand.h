#ifndef NOTIFCOMMAND_H
#define NOTIFCOMMAND_H

#include "FECommand.h"

#include "nscripter.h"

class NotifCommand : public FECommand
{
public:
    NotifCommand();
    bool check(const QString &str) override;
    void execute() override;

private:
    tukineko::NScripter *ns;
};

#endif // NOTIFCOMMAND_H
