#ifndef BTNWAIT2COMMAND_H
#define BTNWAIT2COMMAND_H

#include "ecommand.h"

class Btnwait2Command : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // BTNWAIT2COMMAND_H
