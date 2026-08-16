#ifndef RMODECOMMAND_H
#define RMODECOMMAND_H

#include "ecommand.h"

class RmodeCommand : public ECommand
{
public:
    RmodeCommand();
    virtual ~RmodeCommand();
    bool check(const QString& str);
    void execute();
};

#endif // RMODECOMMAND_H
