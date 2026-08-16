#ifndef INPUTSTRCOMMAND_H
#define INPUTSTRCOMMAND_H

#include "ecommand.h"

class InputstrCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // INPUTSTRCOMMAND_H
