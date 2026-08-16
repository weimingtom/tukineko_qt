#ifndef SUBCOMMAND_H
#define SUBCOMMAND_H

#include <QString>
#include "fecommand.h"

class SubCommand : public FECommand
{
public:
    SubCommand();
    virtual ~SubCommand();

    bool check(const QString& str);
    void execute();
};

#endif // SUBCOMMAND_H
