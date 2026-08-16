#ifndef RESETCOMMAND_H
#define RESETCOMMAND_H

#include "ecommand.h"

class ResetCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // RESETCOMMAND_H
