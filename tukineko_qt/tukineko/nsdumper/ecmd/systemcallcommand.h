#ifndef SYSTEMCALLCOMMAND_H
#define SYSTEMCALLCOMMAND_H

#include "ecommand.h"

class SystemcallCommand : public ECommand
{
public:
    SystemcallCommand();
    virtual ~SystemcallCommand();
    bool check(const QString& str);
    void execute();
};

#endif // SYSTEMCALLCOMMAND_H
