#ifndef LOOKBACKFLUSHCOMMAND_H
#define LOOKBACKFLUSHCOMMAND_H

#include "ecommand.h"

class LookbackflushCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // LOOKBACKFLUSHCOMMAND_H
