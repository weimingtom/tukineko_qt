#ifndef BTNDEFCOMMAND_H
#define BTNDEFCOMMAND_H

#include "ecommand.h"

class BtndefCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // BTNDEFCOMMAND_H
