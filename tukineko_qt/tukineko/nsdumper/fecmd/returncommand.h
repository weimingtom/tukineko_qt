#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include <QString>
#include "fecommand.h"

class ReturnCommand : public FECommand
{
public:
    ReturnCommand();
    virtual ~ReturnCommand();

    bool check(const QString& str);
    void execute();
};

#endif // RETURNCOMMAND_H
