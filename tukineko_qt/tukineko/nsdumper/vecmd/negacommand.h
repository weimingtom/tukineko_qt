#ifndef NEGACOMMAND_H
#define NEGACOMMAND_H

#include <QString>
#include "vecommand.h"

class NegaCommand : public VECommand
{
public:
    NegaCommand();
    virtual ~NegaCommand();

    bool check(const QString& str);
    void execute();
};

#endif // NEGACOMMAND_H

