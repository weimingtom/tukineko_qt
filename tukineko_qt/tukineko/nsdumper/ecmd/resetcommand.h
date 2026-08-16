#ifndef RESETCOMMAND_H
#define RESETCOMMAND_H

#include "ecommand.h"

class ResetCommand : public ECommand
{
public:
    ResetCommand();
    virtual ~ResetCommand();
    bool check(const QString& str);
    void execute();
};

#endif // RESETCOMMAND_H
