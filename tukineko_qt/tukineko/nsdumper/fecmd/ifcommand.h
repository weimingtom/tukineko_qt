#ifndef IFCOMMAND_H
#define IFCOMMAND_H

#include <QString>
#include "fecommand.h"

class IfCommand : public FECommand
{
public:
    IfCommand();
    virtual ~IfCommand();

    bool check(const QString& str);
    void execute();
};

#endif // IFCOMMAND_H
