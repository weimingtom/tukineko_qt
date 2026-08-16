#ifndef SELECTCOMMAND_H
#define SELECTCOMMAND_H

#include "ecommand.h"

class SelectCommand : public ECommand
{
public:
    SelectCommand();
    virtual ~SelectCommand();
    bool check(const QString& str);
    void execute();
};

#endif // SELECTCOMMAND_H
