#ifndef CLICKCOMMAND_H
#define CLICKCOMMAND_H

#include "ecommand.h"

class ClickCommand : public ECommand
{
public:
    ClickCommand();
    virtual ~ClickCommand();
    bool check(const QString& str);
    void execute();
};

#endif // CLICKCOMMAND_H
