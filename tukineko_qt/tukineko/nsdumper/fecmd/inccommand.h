#ifndef INCCOMMAND_H
#define INCCOMMAND_H

#include <QString>
#include "fecommand.h"

class IncCommand : public FECommand
{
public:
    IncCommand();
    virtual ~IncCommand();

    bool check(const QString& str);
    void execute();
};

#endif // INCCOMMAND_H
