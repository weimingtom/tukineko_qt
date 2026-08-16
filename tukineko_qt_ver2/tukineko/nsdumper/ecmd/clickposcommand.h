#ifndef CLICKPOSCOMMAND_H
#define CLICKPOSCOMMAND_H

#include "ecommand.h"

class ClickposCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // CLICKPOSCOMMAND_H
