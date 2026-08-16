#ifndef DELAYCOMMAND_H
#define DELAYCOMMAND_H

#include "ecommand.h"

class DelayCommand : public ECommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // DELAYCOMMAND_H
