#ifndef SYSTEMCALLCOMMAND_H
#define SYSTEMCALLCOMMAND_H

#include "ecommand.h"

class SystemcallCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // SYSTEMCALLCOMMAND_H
