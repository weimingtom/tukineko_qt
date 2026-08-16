#ifndef CLICKPOSCOMMAND_H
#define CLICKPOSCOMMAND_H

#include "ecommand.h"

class ClickposCommand : public ECommand
{
public:
    ClickposCommand();
    virtual ~ClickposCommand();
    bool check(const QString& str);
    void execute();
};

#endif // CLICKPOSCOMMAND_H
