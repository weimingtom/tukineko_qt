#ifndef TRAPCOMMAND_H
#define TRAPCOMMAND_H

#include "ecommand.h"

class TrapCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // TRAPCOMMAND_H
