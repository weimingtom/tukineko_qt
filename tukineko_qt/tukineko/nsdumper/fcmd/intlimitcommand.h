#ifndef INTLIMITCOMMAND_H
#define INTLIMITCOMMAND_H

#include "fcommand.h"

class IntlimitCommand : public FCommand
{
public:
    IntlimitCommand();
    virtual ~IntlimitCommand();

    bool check(const QString& str);
    void execute();
};

#endif // INTLIMITCOMMAND_H
