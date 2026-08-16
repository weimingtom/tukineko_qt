#ifndef CLICKCOMMAND_H
#define CLICKCOMMAND_H

#include "ecommand.h"

class ClickCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // CLICKCOMMAND_H
