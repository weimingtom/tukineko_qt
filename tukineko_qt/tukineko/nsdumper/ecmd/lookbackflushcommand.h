#ifndef LOOKBACKFLUSHCOMMAND_H
#define LOOKBACKFLUSHCOMMAND_H

#include "ecommand.h"

class LookbackflushCommand : public ECommand
{
public:
    LookbackflushCommand();
    virtual ~LookbackflushCommand();
    bool check(const QString& str);
    void execute();
};

#endif // LOOKBACKFLUSHCOMMAND_H
