#ifndef WAITTIMERCOMMAND_H
#define WAITTIMERCOMMAND_H

#include "ecommand.h"

class WaittimerCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // WAITTIMERCOMMAND_H
