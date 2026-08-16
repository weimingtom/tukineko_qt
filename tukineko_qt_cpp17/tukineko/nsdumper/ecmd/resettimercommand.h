#ifndef RESETTIMERCOMMAND_H
#define RESETTIMERCOMMAND_H

#include "ecommand.h"

class ResettimerCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // RESETTIMERCOMMAND_H
