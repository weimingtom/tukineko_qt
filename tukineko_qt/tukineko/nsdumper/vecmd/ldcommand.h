#ifndef LDCOMMAND_H
#define LDCOMMAND_H

#include <QString>
#include "vecommand.h"

class LdCommand : public VECommand
{
public:
    LdCommand();
    virtual ~LdCommand();

    bool check(const QString& str);
    void execute();
};

#endif // LDCOMMAND_H
