#ifndef GETINICOMMAND_H
#define GETINICOMMAND_H

#include <QString>
#include "fecommand.h"

class GetiniCommand : public FECommand
{
public:
    GetiniCommand();
    virtual ~GetiniCommand();

    bool check(const QString& str);
    void execute();
};

#endif // GETINICOMMAND_H
