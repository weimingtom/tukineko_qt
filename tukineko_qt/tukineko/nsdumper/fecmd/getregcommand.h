#ifndef GETREGCOMMAND_H
#define GETREGCOMMAND_H

#include <QString>
#include "fecommand.h"

class GetregCommand : public FECommand
{
public:
    GetregCommand();
    virtual ~GetregCommand();

    bool check(const QString& str);
    void execute();
};

#endif // GETREGCOMMAND_H
