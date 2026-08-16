#ifndef BTNDEFCOMMAND_H
#define BTNDEFCOMMAND_H

#include "ecommand.h"

class BtndefCommand : public ECommand
{
public:
    BtndefCommand();
    virtual ~BtndefCommand();
    bool check(const QString& str);
    void execute();
};

#endif // BTNDEFCOMMAND_H
