#ifndef BTNWAITCOMMAND_H
#define BTNWAITCOMMAND_H

#include "ecommand.h"

class BtnwaitCommand : public ECommand
{
public:
    BtnwaitCommand();
    virtual ~BtnwaitCommand();
    bool check(const QString& str);
    void execute();
};

#endif // BTNWAITCOMMAND_H
