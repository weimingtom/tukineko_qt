#ifndef WAITCOMMAND_H
#define WAITCOMMAND_H

#include "ecommand.h"

class WaitCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // WAITCOMMAND_H
