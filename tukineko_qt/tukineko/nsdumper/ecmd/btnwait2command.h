#ifndef BTNWAIT2COMMAND_H
#define BTNWAIT2COMMAND_H

#include "ecommand.h"

class Btnwait2Command : public ECommand
{
public:
    Btnwait2Command();
    virtual ~Btnwait2Command();
    bool check(const QString& str);
    void execute();
};

#endif // BTNWAIT2COMMAND_H
