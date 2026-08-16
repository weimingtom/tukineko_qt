#ifndef SELECTCOMMAND_H
#define SELECTCOMMAND_H

#include "ecommand.h"

class SelectCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SELECTCOMMAND_H
