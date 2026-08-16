#ifndef INTLIMITCOMMAND_H
#define INTLIMITCOMMAND_H

#include "fcommand.h"

class IntlimitCommand : public FCommand
{
public:
    bool check(const QString &str) override;
    void execute() override;
};

#endif // INTLIMITCOMMAND_H
