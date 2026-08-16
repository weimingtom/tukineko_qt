#ifndef BTNCOMMAND_H
#define BTNCOMMAND_H

#include "ecommand.h"

class BtnCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // BTNCOMMAND_H
