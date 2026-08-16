#ifndef DIVCOMMAND_H
#define DIVCOMMAND_H

#include <QString>
#include "fecommand.h"

class DivCommand : public FECommand
{
public:
    DivCommand();
    virtual ~DivCommand();

    bool check(const QString& str);
    void execute();
};

#endif // DIVCOMMAND_H
