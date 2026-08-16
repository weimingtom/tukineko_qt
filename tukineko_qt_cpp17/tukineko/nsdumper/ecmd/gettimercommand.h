#ifndef GETTIMERCOMMAND_H
#define GETTIMERCOMMAND_H

#include "ecommand.h"

class GettimerCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // GETTIMERCOMMAND_H
