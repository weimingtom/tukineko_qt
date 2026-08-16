#ifndef RMODECOMMAND_H
#define RMODECOMMAND_H

#include "ecommand.h"

class RmodeCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // RMODECOMMAND_H
