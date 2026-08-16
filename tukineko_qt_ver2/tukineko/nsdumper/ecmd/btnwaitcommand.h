#ifndef BTNWAITCOMMAND_H
#define BTNWAITCOMMAND_H

#include "ecommand.h"

class BtnwaitCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // BTNWAITCOMMAND_H
