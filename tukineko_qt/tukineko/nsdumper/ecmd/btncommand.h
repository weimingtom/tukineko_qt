#ifndef BTNCOMMAND_H
#define BTNCOMMAND_H

#include "ecommand.h"

class BtnCommand : public ECommand
{
public:
    BtnCommand();
    virtual ~BtnCommand();
    bool check(const QString& str);
    void execute();
};

#endif // BTNCOMMAND_H
